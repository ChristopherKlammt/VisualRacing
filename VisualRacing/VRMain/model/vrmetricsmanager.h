#ifndef VRMETRICSMANAGER_H
#define VRMETRICSMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include <QDebug>

#include "vrmetrics.h"
#include "vrdata.h"

class VRMetricsManager : public QObject
{
    Q_OBJECT

private:
    QSharedPointer<VRMetrics> m_metrics;
    QSharedPointer<VRData> m_data;

    bool m_running;

    void updateTireSlip();

public:
    VRMetricsManager(QSharedPointer<VRMetrics> metrics, QSharedPointer<VRData> data);
    ~VRMetricsManager();

    bool isRunning();

signals:

public slots:
   void start();
   void abort();

};

#endif // VRMETRICSMANAGER_H
