#include "vrmetricsmanager.h"

VRMetricsManager::VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data)
{
    this->m_metrics = metrics;
    this->m_data = data;
    this->m_running = true;
}

VRMetricsManager::~VRMetricsManager()
{

}

bool VRMetricsManager::isRunning()
{
    return this->m_running;
}

void VRMetricsManager::start()
{
    qDebug() << "Metrics Manager is started.";
    while(this->m_running){
        // update matrics
        this->updateAccelBehav();
        Sleep(1000);
    }
}

void VRMetricsManager::abort()
{
    this->m_running = false;
}

void VRMetricsManager::updateAccelBehav()
{
    float maxGrip = qMax(m_data->getTireGripFL(), m_data->getTireGripFR());
    maxGrip = qMax(maxGrip, m_data->getTireGripRL());
    maxGrip = qMax(maxGrip, m_data->getTireGripRR());

    // scale percentageRPM
    float percentageRPM = m_data->getRpm() / (m_data->getMaxRpm() + 0.00001f);	// TODO: Division by Zero
    if (percentageRPM < 0.1f) {
        percentageRPM = 0;
        m_metrics->setAccelBehav(-1);
        // TODO: -1?
        return;
    } else if (percentageRPM > 0.9f) {
        percentageRPM = 1;
    } else {
        percentageRPM = 1.5625f * percentageRPM * percentageRPM - 0.3125f * percentageRPM + 0.015625f;
    }

    float accelBehav = percentageRPM + maxGrip + m_data->getThrottle();
    accelBehav /= 3;

    m_metrics->setAccelBehav(accelBehav);

    updateAvgAccelBehav(accelBehav);
}

void VRMetricsManager::updateAvgAccelBehav(float accelBehav)
{
    int len = m_accelBehavHistory.length();
    float tmp_avgAccelBehav = m_avgAccelBehav * len; 		// calc the old sum
    float oldestAccelBehav = 0;

    m_accelBehavHistory.enqueue(accelBehav);
    if (len > 1000) {
        oldestAccelBehav = m_accelBehavHistory.dequeue();
    } else {
        len += 1;
    }

    tmp_avgAccelBehav += (accelBehav - oldestAccelBehav);	// calc new sum
    m_avgAccelBehav = tmp_avgAccelBehav / len;				// calc new average

    m_metrics->setAvgAccelBehav(m_avgAccelBehav);
}

