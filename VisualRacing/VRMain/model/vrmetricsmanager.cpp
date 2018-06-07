#include "vrmetricsmanager.h"

VRMetricsManager::VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data)
{
    this->m_metrics = metrics;
    this->m_data = data;

    this->m_avgClutchDisTime = 0l;
    this->m_avgGearChangTime = 0l;

    QObject::connect(m_data.data(), SIGNAL(clutchDisengagedTimeChanged()),
                     this, SLOT(updateClutchDisTime()));
    QObject::connect(m_data.data(), SIGNAL(gearChangeTimeChanged()),
                     this, SLOT(updateGearChangTime()));
    QObject::connect(m_data.data(), SIGNAL(accelBehavChanged()),
                     this, SLOT(updateAccelBehav()));

    // Initialize acceleration behavior info matrix.
    infoMatrix[VRMetrics::Throttle::MAX][VRMetrics::Rpm::HIGH][VRMetrics::Grip::FULL] = VRMetrics::AccelerationBehavior::GOOD;
    infoMatrix[VRMetrics::Throttle::MAX][VRMetrics::Rpm::HIGH][VRMetrics::Grip::LOOSING] = VRMetrics::AccelerationBehavior::LESS_THROTTLE; // ? UPSHIFT
    infoMatrix[VRMetrics::Throttle::MAX][VRMetrics::Rpm::LOW_MED][VRMetrics::Grip::FULL] = VRMetrics::AccelerationBehavior::DOWNSHIFT; // IF IN 1ST -> GOOD
    infoMatrix[VRMetrics::Throttle::MAX][VRMetrics::Rpm::LOW_MED][VRMetrics::Grip::LOOSING] = VRMetrics::AccelerationBehavior::LESS_THROTTLE;

    infoMatrix[VRMetrics::Throttle::MED2HIGH][VRMetrics::Rpm::HIGH][VRMetrics::Grip::FULL] = VRMetrics::AccelerationBehavior::MORE_THROTTLE;
    infoMatrix[VRMetrics::Throttle::MED2HIGH][VRMetrics::Rpm::HIGH][VRMetrics::Grip::LOOSING] = VRMetrics::AccelerationBehavior::LESS_THROTTLE; // ? UPSHIFT
    infoMatrix[VRMetrics::Throttle::MED2HIGH][VRMetrics::Rpm::LOW_MED][VRMetrics::Grip::FULL] = VRMetrics::AccelerationBehavior::MORE_THROTTLE;
    infoMatrix[VRMetrics::Throttle::MED2HIGH][VRMetrics::Rpm::LOW_MED][VRMetrics::Grip::LOOSING] = VRMetrics::AccelerationBehavior::LESS_THROTTLE;

    infoMatrix[VRMetrics::Throttle::LOW2MED][VRMetrics::Rpm::HIGH][VRMetrics::Grip::FULL] = VRMetrics::AccelerationBehavior::MORE_THROTTLE;
    infoMatrix[VRMetrics::Throttle::LOW2MED][VRMetrics::Rpm::HIGH][VRMetrics::Grip::LOOSING] = VRMetrics::AccelerationBehavior::LESS_THROTTLE; // ? UPSHIFT
    infoMatrix[VRMetrics::Throttle::LOW2MED][VRMetrics::Rpm::LOW_MED][VRMetrics::Grip::FULL] = VRMetrics::AccelerationBehavior::MORE_THROTTLE;
    infoMatrix[VRMetrics::Throttle::LOW2MED][VRMetrics::Rpm::LOW_MED][VRMetrics::Grip::LOOSING] = VRMetrics::AccelerationBehavior::LESS_THROTTLE;
}

VRMetricsManager::~VRMetricsManager()
{

}

void VRMetricsManager::updateAccelBehav()
{
    float minGrip = qMin(m_data->getTireGripRL(), m_data->getTireGripRR());
    // TODO: Own makes sense for rear wheel drive cars at the moment.
    //minGrip = qMin(minGrip, m_data->getTireGripFL());
    //minGrip = qMin(minGrip, m_data->getTireGripFR());

    float relRpm = 0.0f;
    if (m_data->getMaxRpm() > 0)
        relRpm = static_cast<float>(m_data->getRpm()) / static_cast<float>(m_data->getMaxRpm());

    // Classify throttle, rpm and grip.
    if (m_data->getThrottle() > 0.95f)
        m_metrics->setThrottleClassification(VRMetrics::Throttle::MAX);
    else if (m_data->getThrottle() > 0.5f)
        m_metrics->setThrottleClassification(VRMetrics::Throttle::MED2HIGH);
    else
        m_metrics->setThrottleClassification(VRMetrics::Throttle::LOW2MED);

    if (relRpm > 0.75f)
        m_metrics->setRpmClassification(VRMetrics::Rpm::HIGH);
    else
        m_metrics->setRpmClassification(VRMetrics::Rpm::LOW_MED);

    if (minGrip > 0.8f)
        m_metrics->setGripClassification(VRMetrics::Grip::FULL);
    else
        m_metrics->setGripClassification(VRMetrics::Grip::LOOSING);

    // Update acceleration behavior by table lookup.
    VRMetrics::AccelerationBehavior tmp = infoMatrix[m_metrics->getThrottleClassification()][m_metrics->getRpmClassification()][m_metrics->getGripClassification()];

    if (m_metrics->getThrottleClassification() == VRMetrics::Throttle::MAX
            && m_metrics->getRpmClassification() == VRMetrics::Rpm::LOW_MED
            && m_metrics->getGripClassification() == VRMetrics::Grip::FULL) {
        // If in first gear, don't recommend to downshift, we are good in this case.
        if (m_data->getGear() == 1)
            tmp = VRMetrics::AccelerationBehavior::GOOD;
    }

    m_metrics->setAccelBehav(tmp);
}

void VRMetricsManager::updateClutchDisTime()
{
    long tmp_clutchDisTime = m_data->getClutchDisengagedTime();
    m_metrics->setClutchDisengagedTime(tmp_clutchDisTime);

    updateAvgClutchDisTime(tmp_clutchDisTime);
}

void VRMetricsManager::updateAvgClutchDisTime(long clutchDisTime)
{
    // Get difference between new value and old average
    if (m_metrics->getMinClutchDisTime() != -1)
        m_metrics->setDiffToAvgShiftTime(clutchDisTime - m_metrics->getAvgClutchDisTime());
    // Store min clutch dis time (has to happen after diff changes!)
    if (m_metrics->getMinClutchDisTime() == -1l || clutchDisTime < m_metrics->getMinClutchDisTime())
        m_metrics->setMinClutchDisTime(clutchDisTime);


    // Attention take a look on rounding Error with this Algorithm
    int len = m_clutchDisTimeHistory.length();
    long tmp_avgClutchDisTime = m_avgClutchDisTime * len;               // calc the old sum by mult with number of elements
    long oldestClutchDisTime = 0;

    m_clutchDisTimeHistory.enqueue(clutchDisTime);                      // add new value to history
    if (len > 1000) {
        oldestClutchDisTime = m_clutchDisTimeHistory.dequeue();         // remove the oldest value if queue to long
    } else {
        len += 1;                                                       // if not too long increment tmp length
    }

    tmp_avgClutchDisTime += (clutchDisTime -  oldestClutchDisTime);     // calc new sum by adding the diff between new and oldest value
    m_avgClutchDisTime = tmp_avgClutchDisTime / len;                    // calc new average by deviding through new length (amount of values)

    m_metrics->setAvgClutchDisTime(m_avgClutchDisTime);
}

void VRMetricsManager::updateGearChangTime()
{
    long tmp_gearChangTime = m_data->getGearChangeTime();
    m_metrics->setGearChangeTime(tmp_gearChangTime);

    updateAvgGearChangTime(tmp_gearChangTime);
}

void VRMetricsManager::updateAvgGearChangTime(long gearChangTime)
{
    // Attention take a look on rounding Error with this Algorithm
    int len = m_gearChangTimeHistory.length();
    long tmp_avgGearChangTime = m_avgGearChangTime * len;
    long oldestGearChangTime = 0;

    m_gearChangTimeHistory.enqueue(gearChangTime);
    if (len > 1000) {
        oldestGearChangTime = m_gearChangTimeHistory.dequeue();
    } else {
        len += 1;
    }

    tmp_avgGearChangTime += (gearChangTime - oldestGearChangTime);
    m_avgGearChangTime = tmp_avgGearChangTime / len;

    m_metrics->setAvgGearChangTime(m_avgGearChangTime);
}

