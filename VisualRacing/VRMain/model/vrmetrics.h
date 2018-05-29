#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float accelBehav READ getAccelBehav WRITE setAccelBehav NOTIFY accelBehavChanged)
    Q_PROPERTY(float avgAccelBehav READ getAvgAccelBehav WRITE setAvgAccelBehav NOTIFY avgAccelBehavChanged)
    Q_PROPERTY(float shiftTime READ getShiftTime WRITE setShiftTime NOTIFY shiftTimeChanged)

public:
    VRMetrics();
    ~VRMetrics();

    float getAccelBehav() const;
    void setAccelBehav(float value);

    float getAvgAccelBehav() const;
    void setAvgAccelBehav(float value);

    float getShiftTime() const;
    void setShiftTime(float value);

signals:
    void accelBehavChanged();
    void avgAccelBehavChanged();
    void shiftTimeChanged();

private:

    float accelBehav;
    float avgAccelBehav;
    float shiftTime;
};

#endif // VRMETRICS_H
