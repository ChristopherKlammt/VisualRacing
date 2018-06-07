#ifndef VRMETRICSMANAGER_H
#define VRMETRICSMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include <QDebug>
#include <QQueue>

#include "vrmetrics.h"
#include "vrdata.h"

class VRMetricsManager : public QObject
{
    Q_OBJECT

private:
    QSharedPointer<VRMetrics> m_metrics;
    QSharedPointer<VRData> m_data;

    VRMetrics::AccelerationBehavior infoMatrix[VRMetrics::Throttle::_T_COUNT][VRMetrics::Rpm::_R_COUNT][VRMetrics::Grip::_G_COUNT];

    long m_avgClutchDisTime;
    QQueue<long> m_clutchDisTimeHistory;

    long m_avgGearChangTime;
    QQueue<long> m_gearChangTimeHistory;

    void updateAvgClutchDisTime(long clutchDisTime);
    void updateAvgGearChangTime(long gearChangTime);

public:
    VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data);
    ~VRMetricsManager();

signals:

public slots:
    void updateAccelBehav();
    void updateClutchDisTime();
    void updateGearChangTime();
};

#endif // VRMETRICSMANAGER_H
