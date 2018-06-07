#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT

    // Upshift
    Q_PROPERTY(long clutchDisengagedTime READ getClutchDisengagedTime WRITE setClutchDisengagedTime NOTIFY clutchDisengagedTimeChanged)
    Q_PROPERTY(long gearChangeTime READ getGearChangeTime WRITE setGearChangeTime NOTIFY gearChangeTimeChanged)
    Q_PROPERTY(long avgClutchDisTime READ getAvgClutchDisTime WRITE setAvgClutchDisTime NOTIFY avgClutchDisTimeChanged)
    Q_PROPERTY(long avgGearChangTime READ getAvgGearChangTime WRITE setAvgGearChangTime NOTIFY avgGearChangTimeChanged)
    Q_PROPERTY(long diffToAvgShiftTime READ getDiffToAvgShiftTime WRITE setDiffToAvgShiftTime NOTIFY diffToAvgShiftTimeChanged)
    Q_PROPERTY(long minClutchDisTime READ getMinClutchDisTime WRITE setMinClutchDisTime NOTIFY minClutchDisTimeChanged)

    // Acceleration
    Q_PROPERTY(Throttle throttleClassification READ getThrottleClassification WRITE setThrottleClassification NOTIFY throttleClassificationChanged)
    Q_PROPERTY(Rpm rpmClassification READ getRpmClassification WRITE setRpmClassification NOTIFY rpmClassificationChanged)
    Q_PROPERTY(Grip gripClassification READ getGripClassification WRITE setGripClassification NOTIFY gripClassificationChanged)
    Q_PROPERTY(AccelerationBehavior accelBehav READ getAccelBehav WRITE setAccelBehav NOTIFY accelBehavChanged)

public:
    // Acceleration

    // ATTENTION: Those are also used to index arrays !!!
    enum Throttle { MAX, MED2HIGH, LOW2MED, _T_COUNT };
    Q_ENUM(Throttle)
    enum Rpm { HIGH, LOW_MED, _R_COUNT };
    Q_ENUM(Rpm)
    enum Grip { FULL, LOOSING, _G_COUNT };
    Q_ENUM(Grip)

    enum AccelerationBehavior { GOOD, MORE_THROTTLE, LESS_THROTTLE, UPSHIFT, DOWNSHIFT };
    Q_ENUM(AccelerationBehavior)

    VRMetrics();
    ~VRMetrics();

    // Upshift
    long getClutchDisengagedTime() const;
    void setClutchDisengagedTime(long value);

    long getGearChangeTime() const;
    void setGearChangeTime(long value);

    long getAvgClutchDisTime() const;
    void setAvgClutchDisTime(long value);

    long getAvgGearChangTime() const;
    void setAvgGearChangTime(long value);

    long getDiffToAvgShiftTime() const;
    void setDiffToAvgShiftTime(long value);

    long getMinClutchDisTime() const;
    void setMinClutchDisTime(long value);

    // Acceleration
    Throttle getThrottleClassification() const;
    void setThrottleClassification(const Throttle &value);

    Rpm getRpmClassification() const;
    void setRpmClassification(const Rpm &value);

    Grip getGripClassification() const;
    void setGripClassification(const Grip &value);

    AccelerationBehavior getAccelBehav() const;
    void setAccelBehav(const AccelerationBehavior &value);

signals:
    // Upshift
    void clutchDisengagedTimeChanged();
    void gearChangeTimeChanged();
    void avgClutchDisTimeChanged();
    void avgGearChangTimeChanged();
    void diffToAvgShiftTimeChanged();
    void minClutchDisTimeChanged();

    // Acceleration
    void throttleClassificationChanged();
    void rpmClassificationChanged();
    void gripClassificationChanged();
    void accelBehavChanged();

private:
    // Upshift
    long clutchDisengagedTime;
    long gearChangeTime;
    long avgClutchDisTime;
    long avgGearChangTime;
    long diffToAvgShiftTime;
    long minClutchDisTime;

    // Acceleration
    Throttle throttleClassification;
    Rpm rpmClassification;
    Grip gripClassification;
    AccelerationBehavior accelBehav;
};

Q_DECLARE_METATYPE(VRMetrics::Throttle)
Q_DECLARE_METATYPE(VRMetrics::Rpm)
Q_DECLARE_METATYPE(VRMetrics::Grip)
Q_DECLARE_METATYPE(VRMetrics::AccelerationBehavior)

#endif // VRMETRICS_H
