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
    float i = 0.1f;
    while(this->m_running){
        // update matrics
        float tmp_shiftBehaviour = m_data->getClutch() + i;
        m_metrics->setUpShiftBehaviour(tmp_shiftBehaviour);
        i += 0.1f;
        Sleep(1000);
    }
}

void VRMetricsManager::abort()
{
    this->m_running = false;
}
