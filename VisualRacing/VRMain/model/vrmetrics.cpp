#include "vrmetrics.h"

VRMetrics::VRMetrics()
{
    // Upshift
    this->clutchDisengagedTime = 0l;
    this->avgClutchDisTime = 0l;
    this->gearChangeTime = 0l;
    this->avgGearChangTime = 0l;
    this->diffToAvgShiftTime = 0l;
    this->minClutchDisTime = -1l;

    // Acceleration
    this->throttleClassification = Throttle::LOW2MED;
    this->rpmClassification = Rpm::LOW_MED;
    this->gripClassification = Grip::FULL;
    this->accelBehav = AccelerationBehavior::GOOD;
}

VRMetrics::~VRMetrics()
{

}

long VRMetrics::getClutchDisengagedTime() const
{
    return clutchDisengagedTime;
}

void VRMetrics::setClutchDisengagedTime(long value)
{
    clutchDisengagedTime = value;
    emit clutchDisengagedTimeChanged();
}

long VRMetrics::getGearChangeTime() const
{
    return gearChangeTime;
}

void VRMetrics::setGearChangeTime(long value)
{
    gearChangeTime = value;
    emit gearChangeTimeChanged();
}

long VRMetrics::getAvgClutchDisTime() const
{
    return avgClutchDisTime;
}

void VRMetrics::setAvgClutchDisTime(long value)
{
    avgClutchDisTime = value;
    emit avgClutchDisTimeChanged();
}

long VRMetrics::getAvgGearChangTime() const
{
    return avgGearChangTime;
}

void VRMetrics::setAvgGearChangTime(long value)
{
    avgGearChangTime = value;
    emit avgGearChangTimeChanged();
}

long VRMetrics::getDiffToAvgShiftTime() const
{
    return diffToAvgShiftTime;
}

void VRMetrics::setDiffToAvgShiftTime(long value)
{
    diffToAvgShiftTime = value;
    emit diffToAvgShiftTimeChanged();
}

long VRMetrics::getMinClutchDisTime() const
{
    return minClutchDisTime;
}

void VRMetrics::setMinClutchDisTime(long value)
{
    minClutchDisTime = value;
    emit minClutchDisTimeChanged();
}

VRMetrics::Throttle VRMetrics::getThrottleClassification() const
{
    return throttleClassification;
}

void VRMetrics::setThrottleClassification(const Throttle &value)
{
    //if (value == throttleClassification)
    //    return;

    throttleClassification = value;
    emit throttleClassificationChanged();
}

VRMetrics::Rpm VRMetrics::getRpmClassification() const
{
    return rpmClassification;
}

void VRMetrics::setRpmClassification(const Rpm &value)
{
    //if (value == rpmClassification)
    //    return;

    rpmClassification = value;
    emit rpmClassificationChanged();
}

VRMetrics::Grip VRMetrics::getGripClassification() const
{
    return gripClassification;
}

void VRMetrics::setGripClassification(const Grip &value)
{
    //if (value == gripClassification)
    //    return;

    gripClassification = value;
    emit gripClassificationChanged();
}

VRMetrics::AccelerationBehavior VRMetrics::getAccelBehav() const
{
    return accelBehav;
}

void VRMetrics::setAccelBehav(const AccelerationBehavior &value)
{
    //if (value == accelBehav)
    //    return;

    accelBehav = value;
    emit accelBehavChanged();
}
