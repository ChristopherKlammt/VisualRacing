#include "vrdata.h"

VRData::VRData()
{
    this->startTime = VRUtilities::getCurrentTime();

    this->gear = 0;
    this->velocity = 0.0f;
    this->rpm = 0;
    this->maxRpm = 0;

    this->throttle = 0.0f;
    this->brake = 0.0f;
    this->clutch = 0.0f;

    this->completedLaps = 0;

    this->fuel = 0.0f;
    this->maxFuel = 0.0f;

    this->pitLimiter = false;
    this->isInPitlane = false;

    this->brakeBias = 0.0f;

    this->currentLapTime = 0.0f;
    this->bestLapTime = 0.0f;
    this->previousLapTime = 0.0f;

    this->tireWearFL = 0.0f;
    this->tireWearFR = 0.0f;
    this->tireWearRR = 0.0f;
    this->tireWearRL = 0.0f;

    this->tireTemperatureFLI = 0.0f;
    this->tireTemperatureFLC = 0.0f;
    this->tireTemperatureFLO = 0.0f;

    this->tireTemperatureFRI = 0.0f;
    this->tireTemperatureFRC = 0.0f;
    this->tireTemperatureFRO = 0.0f;

    this->tireTemperatureRRI = 0.0f;
    this->tireTemperatureRRC = 0.0f;
    this->tireTemperatureRRO = 0.0f;

    this->tireTemperatureRLI = 0.0f;
    this->tireTemperatureRLC = 0.0f;
    this->tireTemperatureRLO = 0.0f;

    this->brakeTemperatureFL = 0.0f;
    this->brakeTemperatureFR = 0.0f;
    this->brakeTemperatureRR = 0.0f;
    this->brakeTemperatureRL = 0.0f;

    this->tirePressureFL = 0.0f;
    this->tirePressureFR = 0.0f;
    this->tirePressureRR = 0.0f;
    this->tirePressureRL = 0.0f;

    this->tireDirtFL = 0.0f;
    this->tireDirtFR = 0.0f;
    this->tireDirtRR = 0.0f;
    this->tireDirtRL = 0.0f;

    this->currentS1 = 0.0f;
    this->currentS2 = 0.0f;
    this->currentS3 = 0.0f;

    this->bestS1 = 0.0f;
    this->bestS2 = 0.0f;
    this->bestS3 = 0.0f;

    this->previousS1 = 0.0f;
    this->previousS2 = 0.0f;
    this->previousS3 = 0.0f;

    this->tBestS1 = 0.0f;
    this->tBestS2 = 0.0f;
    this->tBestS3 = 0.0f;

    this->tireGripFL = 0.0f;
    this->tireGripFR = 0.0f;
    this->tireGripRR = 0.0f;
    this->tireGripRL = 0.0f;

    this->lapDistance = 0.0f;

    this->clutchDisengagedTime = 0l;
    this->gearChangeTime = 0l;
}

double VRData::getTimeInSeconds()
{
    std::chrono::milliseconds now = VRUtilities::getCurrentTime();
    return (now.count() - startTime.count()) * 0.001;
}

int VRData::getGear() const
{
    return gear;
}

void VRData::setGear(int value)
{
    if (gear == value)
        return;

    gear = value;
    emit gearChanged();
}

float VRData::getVelocity() const
{
    return velocity;
}

void VRData::setVelocity(float value)
{
    if (velocity == value)
        return;

    velocity = value;
    emit velocityChanged();
}

int VRData::getRpm() const
{
    return rpm;
}

void VRData::setRpm(int value)
{
    if (rpm == value)
        return;

    rpm = value;
    emit rpmChanged();
}

int VRData::getMaxRpm() const
{
    return maxRpm;
}

void VRData::setMaxRpm(int value)
{
    if (maxRpm == value)
        return;

    maxRpm = value;
    emit maxRpmChanged();
}

float VRData::getThrottle() const
{
    return throttle;
}

void VRData::setThrottle(float value)
{
    if (throttle == value)
        return;

    throttle = value;
    emit throttleChanged();
}

float VRData::getBrake() const
{
    return brake;
}

void VRData::setBrake(float value)
{
    if (brake == value)
        return;

    brake = value;
    emit brakeChanged();
}

float VRData::getClutch() const
{
    return clutch;
}

void VRData::setClutch(float value)
{
    if (clutch == value)
        return;

    clutch = value;
    emit clutchChanged();
}

int VRData::getCompletedLaps() const
{
    return completedLaps;
}

void VRData::setCompletedLaps(int value)
{
    if (completedLaps == value)
        return;

    completedLaps = value;
    emit completedLapsChanged();
}

float VRData::getFuel() const
{
    return fuel;
}

void VRData::setFuel(float value)
{
    if (fuel == value)
        return;

    fuel = value;
    emit fuelChanged();
}

float VRData::getMaxFuel() const
{
    return maxFuel;
}

void VRData::setMaxFuel(float value)
{
    if (maxFuel == value)
        return;

    maxFuel = value;
    emit maxFuelChanged();
}

bool VRData::getPitLimiter() const
{
    return pitLimiter;
}

void VRData::setPitLimiter(bool value)
{
    if (pitLimiter == value)
        return;

    pitLimiter = value;
    emit pitLimiterChanged();
}

bool VRData::getIsInPitlane() const
{
    return isInPitlane;
}

void VRData::setIsInPitlane(bool value)
{
    if (isInPitlane == value)
        return;

    isInPitlane = value;
    emit isInPitlaneChanged();
}

float VRData::getBrakeBias() const
{
    return brakeBias;
}

void VRData::setBrakeBias(float value)
{
    if (brakeBias == value)
        return;

    brakeBias = value;
    emit brakeBiasChanged();
}

float VRData::getCurrentLapTime() const
{
    return currentLapTime;
}

void VRData::setCurrentLapTime(float value)
{
    if (currentLapTime == value)
        return;

    currentLapTime = value;
    emit currentLapTimeChanged();
}

float VRData::getBestLapTime() const
{
    return bestLapTime;
}

void VRData::setBestLapTime(float value)
{
    if (bestLapTime == value)
            return;

    bestLapTime = value;
    emit bestLapTimeChanged();
}

float VRData::getPreviousLapTime() const
{
    return previousLapTime;
}

void VRData::setPreviousLapTime(float value)
{
    if (previousLapTime == value)
        return;

    previousLapTime = value;
    emit previousLapTimeChanged();
}

float VRData::getTireWearFL() const
{
    return tireWearFL;
}

void VRData::setTireWearFL(float value)
{
    if (tireWearFL == value)
        return;

    tireWearFL = value;
    emit tireWearFLChanged();
}

float VRData::getTireWearFR() const
{
    return tireWearFR;
}

void VRData::setTireWearFR(float value)
{
    if (tireWearFR == value)
        return;

    tireWearFR = value;
    emit tireWearFRChanged();
}

float VRData::getTireWearRR() const
{
    return tireWearRR;
}

void VRData::setTireWearRR(float value)
{
    if(tireWearRR == value)
        return;

    tireWearRR = value;
    emit tireWearRRChanged();
}

float VRData::getTireWearRL() const
{
    return tireWearRL;
}

void VRData::setTireWearRL(float value)
{
    if (tireWearRL == value)
        return;

    tireWearRL = value;
    emit tireWearRLChanged();
}

float VRData::getTireTemperatureFLI() const
{
    return tireTemperatureFLI;
}

void VRData::setTireTemperatureFLI(float value)
{
    if (value == tireTemperatureFLI)
        return;

    tireTemperatureFLI = value;
    emit tireTemperatureFLIChanged();
}

float VRData::getTireTemperatureFLC() const
{
    return tireTemperatureFLC;
}

void VRData::setTireTemperatureFLC(float value)
{
    if (value == tireTemperatureFLC)
        return;

    tireTemperatureFLC = value;
    emit tireTemperatureFLCChanged();
}

float VRData::getTireTemperatureFLO() const
{
    return tireTemperatureFLO;
}

void VRData::setTireTemperatureFLO(float value)
{
    if (value == tireTemperatureFLO)
        return;

    tireTemperatureFLO = value;
    emit tireTemperatureFLOChanged();
}

float VRData::getTireTemperatureFRI() const
{
    return tireTemperatureFRI;
}

void VRData::setTireTemperatureFRI(float value)
{
    if (value == tireTemperatureFRI)
        return;

    tireTemperatureFRI = value;
    emit tireTemperatureFRIChanged();
}

float VRData::getTireTemperatureFRC() const
{
    return tireTemperatureFRC;
}

void VRData::setTireTemperatureFRC(float value)
{
    if (value == tireTemperatureFRC)
        return;

    tireTemperatureFRC = value;
    emit tireTemperatureFRCChanged();
}

float VRData::getTireTemperatureFRO() const
{
    return tireTemperatureFRO;
}

void VRData::setTireTemperatureFRO(float value)
{
    if (value == tireTemperatureFRO)
        return;

    tireTemperatureFRO = value;
    emit tireTemperatureFROChanged();
}

float VRData::getTireTemperatureRRI() const
{
    return tireTemperatureRRI;
}

void VRData::setTireTemperatureRRI(float value)
{
    if (value == tireTemperatureRRI)
        return;

    tireTemperatureRRI = value;
    emit tireTemperatureRRIChanged();
}

float VRData::getTireTemperatureRRC() const
{
    return tireTemperatureRRC;
}

void VRData::setTireTemperatureRRC(float value)
{
    if (value == tireTemperatureRRC)
        return;

    tireTemperatureRRC = value;
    emit tireTemperatureRRCChanged();
}

float VRData::getTireTemperatureRRO() const
{
    return tireTemperatureRRO;
}

void VRData::setTireTemperatureRRO(float value)
{
    if (value == tireTemperatureRRO)
        return;

    tireTemperatureRRO = value;
    emit tireTemperatureRROChanged();
}

float VRData::getTireTemperatureRLI() const
{
    return tireTemperatureRLI;
}

void VRData::setTireTemperatureRLI(float value)
{
    if (value == tireTemperatureRLI)
        return;

    tireTemperatureRLI = value;
    emit tireTemperatureRLIChanged();
}

float VRData::getTireTemperatureRLC() const
{
    return tireTemperatureRLC;
}

void VRData::setTireTemperatureRLC(float value)
{
    if (value == tireTemperatureRLC)
        return;

    tireTemperatureRLC = value;
    emit tireTemperatureRLCChanged();
}

float VRData::getTireTemperatureRLO() const
{
    return tireTemperatureRLO;
}

void VRData::setTireTemperatureRLO(float value)
{
    if (value == tireTemperatureRLO)
        return;

    tireTemperatureRLO = value;
    emit tireTemperatureRLOChanged();
}

float VRData::getBrakeTemperatureFL() const
{
    return brakeTemperatureFL;
}

void VRData::setBrakeTemperatureFL(float value)
{
    if (brakeTemperatureFL == value)
        return;

    brakeTemperatureFL = value;
    emit brakeTemperatureFLChanged();
}

float VRData::getBrakeTemperatureFR() const
{
    return brakeTemperatureFR;
}

void VRData::setBrakeTemperatureFR(float value)
{
    if (brakeTemperatureFR == value)
        return;

    brakeTemperatureFR = value;
    emit brakeTemperatureFRChanged();
}

float VRData::getBrakeTemperatureRR() const
{
    return brakeTemperatureRR;
}

void VRData::setBrakeTemperatureRR(float value)
{
    if (brakeTemperatureRR == value)
        return;

    brakeTemperatureRR = value;
    emit brakeTemperatureRRChanged();
}

float VRData::getBrakeTemperatureRL() const
{
    return brakeTemperatureRL;
}

void VRData::setBrakeTemperatureRL(float value)
{
    if (brakeTemperatureRL == value)
        return;

    brakeTemperatureRL = value;
    emit brakeTemperatureRLChanged();
}

float VRData::getTirePressureFL() const
{
    return tirePressureFL;
}

void VRData::setTirePressureFL(float value)
{
    if (tirePressureFL == value)
        return;

    tirePressureFL = value;
    emit tirePressureFLChanged();
}

float VRData::getTirePressureFR() const
{
    return tirePressureFR;
}

void VRData::setTirePressureFR(float value)
{
    if (tirePressureFR == value)
        return;

    tirePressureFR = value;
    emit tirePressureFRChanged();
}

float VRData::getTirePressureRR() const
{
    return tirePressureRR;
}

void VRData::setTirePressureRR(float value)
{
    if (tirePressureRR == value)
        return;

    tirePressureRR = value;
    emit tirePressureRRChanged();
}

float VRData::getTirePressureRL() const
{
    return tirePressureRL;
}

void VRData::setTirePressureRL(float value)
{
    if (tirePressureRL == value)
        return;

    tirePressureRL = value;
    emit tirePressureRLChanged();
}

float VRData::getTireDirtFL() const
{
    return tireDirtFL;
}

void VRData::setTireDirtFL(float value)
{
    if (tireDirtFL == value)
        return;

    tireDirtFL = value;
    emit tireDirtFLChanged();
}

float VRData::getTireDirtFR() const
{
    return tireDirtFR;
}

void VRData::setTireDirtFR(float value)
{
    if (tireDirtFR == value)
        return;

    tireDirtFR = value;
    emit tireDirtFRChanged();
}

float VRData::getTireDirtRR() const
{
    return tireDirtRR;
}

void VRData::setTireDirtRR(float value)
{
    if (tireDirtRR == value)
        return;

    tireDirtRR = value;
    emit tireDirtRRChanged();
}

float VRData::getTireDirtRL() const
{
    return tireDirtRL;
}

void VRData::setTireDirtRL(float value)
{
    if (tireDirtRL == value)
        return;

    tireDirtRL = value;
    emit tireDirtRLChanged();
}

float VRData::getCurrentS1() const
{
    return currentS1;
}

void VRData::setCurrentS1(float value)
{
    if (currentS1 == value)
        return;

    currentS1 = value;
    emit currentS1Changed();
}

float VRData::getCurrentS2() const
{
    return currentS2;
}

void VRData::setCurrentS2(float value)
{
    if (currentS2 == value)
        return;

    currentS2 = value;
    emit currentS2Changed();
}

float VRData::getCurrentS3() const
{
    return currentS3;
}

void VRData::setCurrentS3(float value)
{
    if (currentS3 == value)
        return;

    currentS3 = value;
    emit currentS3Changed();
}

float VRData::getBestS1() const
{
    return bestS1;
}

void VRData::setBestS1(float value)
{
    if (bestS1 == value)
        return;

    bestS1 = value;
    emit bestS1Changed();
}

float VRData::getBestS2() const
{
    return bestS2;
}

void VRData::setBestS2(float value)
{
    if (bestS2 == value)
        return;

    bestS2 = value;
    emit bestS2Changed();
}

float VRData::getBestS3() const
{
    return bestS3;
}

void VRData::setBestS3(float value)
{
    if (bestS3 == value)
        return;

    bestS3 = value;
    emit bestS3Changed();
}

float VRData::getPreviousS1() const
{
    return previousS1;
}

void VRData::setPreviousS1(float value)
{
    if (previousS1 == value)
        return;

    previousS1 = value;
    emit previousS1Changed();
}

float VRData::getPreviousS2() const
{
    return previousS2;
}

void VRData::setPreviousS2(float value)
{
    if (previousS2 == value)
        return;

    previousS2 = value;
    emit previousS2Changed();
}

float VRData::getPreviousS3() const
{
    return previousS3;
}

void VRData::setPreviousS3(float value)
{
    if (previousS3 == value)
        return;

    previousS3 = value;
    emit previousS3Changed();
}

float VRData::getTBestS1() const
{
    return tBestS1;
}

void VRData::setTBestS1(float value)
{
    if (tBestS1 == value)
        return;

    tBestS1 = value;
    emit tBestSChanged();
}

float VRData::getTBestS2() const
{
    return tBestS2;
}

void VRData::setTBestS2(float value)
{
    if(tBestS2 == value)
        return;

    tBestS2 = value;
    emit tBestSChanged();
}

float VRData::getTBestS3() const
{
    return tBestS3;
}

void VRData::setTBestS3(float value)
{
    if (tBestS3 == value)
        return;

    tBestS3 = value;
    emit tBestSChanged();
}

float VRData::getTireGripFL() const
{
    return tireGripFL;
}

void VRData::setTireGripFL(float value)
{
    if (tireGripFL == value)
        return;

    tireGripFL = value;
    emit tireGripFLChanged();
}

float VRData::getTireGripFR() const
{
    return tireGripFR;
}

void VRData::setTireGripFR(float value)
{
    if (tireGripFR == value)
        return;

    tireGripFR = value;
    emit tireGripFRChanged();
}

float VRData::getTireGripRR() const
{
    return tireGripRR;
}

void VRData::setTireGripRR(float value)
{
    if (tireGripRR == value)
        return;

    tireGripRR = value;
    emit tireGripRRChanged();
}

float VRData::getTireGripRL() const
{
    return tireGripRL;
}

void VRData::setTireGripRL(float value)
{
    if (tireGripRL == value)
        return;

    tireGripRL = value;
    emit tireGripRLChanged();
}

float VRData::getLapDistance() const
{
    return lapDistance;
}

void VRData::setLapDistance(float value)
{
    if (value == lapDistance)
        return;

    lapDistance = value;
    emit lapDistanceChanged();
}

long VRData::getClutchDisengagedTime() const
{
    return clutchDisengagedTime;
}

void VRData::setClutchDisengagedTime(long value)
{
    clutchDisengagedTime = value;
    emit clutchDisengagedTimeChanged();
}

long VRData::getGearChangeTime() const
{
    return gearChangeTime;
}

void VRData::setGearChangeTime(long value)
{
    gearChangeTime = value;
    emit gearChangeTimeChanged();
}
