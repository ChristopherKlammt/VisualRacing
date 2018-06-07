#include "vrdatainterfacer3e.h"

VRDataInterfaceR3E::VRDataInterfaceR3E() : VRDataInterface(vrconstants::r3eProcessName) {
    this->access = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->access->setNativeKey(vrconstants::r3eSharedMemoryName);
    this->nativeBuffer = nullptr;
  
    this->shiftTimeData = {};
}

VRDataInterfaceR3E::~VRDataInterfaceR3E() {
    this->stop();
}

bool VRDataInterfaceR3E::start() {
    bool success = this->access->attach(QSharedMemory::AccessMode::ReadOnly);
    if (success)
        this->nativeBuffer = static_cast<r3e_shared*>(this->access->data());

    return success;
}

void VRDataInterfaceR3E::stop() {
    this->access->detach();
}

bool VRDataInterfaceR3E::update() {
    if (!this->access->isAttached())
        return false;

    // TODO: Static information like playerName, carName and trackName do not need to be set every update.

    if(!this->shiftTimeData.clutchDisengaged)
        this->shiftTimeData.lastGear = this->buffer->getGear();

    this->buffer->setGear(this->nativeBuffer->gear == -2 ? 0 : this->nativeBuffer->gear);
    this->buffer->setVelocity(qMax(this->nativeBuffer->car_speed * 3.6f, 0.0f)); // Conversion from m/s to km/h
    this->buffer->setRpm(qMax(this->nativeBuffer->engine_rps * (60 / (2 * M_PI)), 0.0)); // Conversion from rps to rpm
    this->buffer->setMaxRpm(qMax(this->nativeBuffer->max_engine_rps * (60 / (2 * M_PI)), 1.0)); // Conversion from rps to rpm

    this->buffer->setThrottle(qMax(this->nativeBuffer->throttle_pedal, 0.0f));
    this->buffer->setBrake(qMax(this->nativeBuffer->brake_pedal, 0.0f));
    this->buffer->setClutch(qMax(this->nativeBuffer->clutch_pedal, 0.0f));

    this->buffer->setCompletedLaps(this->nativeBuffer->completed_laps);

    this->buffer->setFuel(qMax(this->nativeBuffer->fuel_left, 0.0f));
    this->buffer->setMaxFuel(qMax(this->nativeBuffer->fuel_capacity, 0.0f));

    this->buffer->setPitLimiter(this->nativeBuffer->pit_limiter > 0 ? true : false);
    this->buffer->setIsInPitlane(this->nativeBuffer->in_pitlane > 0 ? true : false);

    this->buffer->setBrakeBias(qMax(1.0f - this->nativeBuffer->brake_bias, 0.0f));

    this->buffer->setCurrentLapTime(qMax(this->nativeBuffer->lap_time_current_self, 0.0f));
    this->buffer->setBestLapTime(qMax(this->nativeBuffer->lap_time_best_self, 0.0f));
    this->buffer->setPreviousLapTime(qMax(this->nativeBuffer->lap_time_previous_self, 0.0f));

    this->buffer->setTireWearFL(qMax(this->nativeBuffer->tire_wear[R3E_TIRE_FRONT_LEFT], 0.0f));
    this->buffer->setTireWearFR(qMax(this->nativeBuffer->tire_wear[R3E_TIRE_FRONT_RIGHT], 0.0f));
    this->buffer->setTireWearRR(qMax(this->nativeBuffer->tire_wear[R3E_TIRE_REAR_RIGHT], 0.0f));
    this->buffer->setTireWearRL(qMax(this->nativeBuffer->tire_wear[R3E_TIRE_REAR_LEFT], 0.0f));

    this->buffer->setTireTemperatureFLI(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_FRONT_LEFT][R3E_TIRE_TEMP_RIGHT], 0.0f));
    this->buffer->setTireTemperatureFLC(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_FRONT_LEFT][R3E_TIRE_TEMP_CENTER], 0.0f));
    this->buffer->setTireTemperatureFLO(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_FRONT_LEFT][R3E_TIRE_TEMP_LEFT], 0.0f));

    this->buffer->setTireTemperatureFRI(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_FRONT_RIGHT][R3E_TIRE_TEMP_LEFT], 0.0f));
    this->buffer->setTireTemperatureFRC(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_FRONT_RIGHT][R3E_TIRE_TEMP_CENTER], 0.0f));
    this->buffer->setTireTemperatureFRO(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_FRONT_RIGHT][R3E_TIRE_TEMP_RIGHT], 0.0f));

    this->buffer->setTireTemperatureRRI(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_REAR_RIGHT][R3E_TIRE_TEMP_LEFT], 0.0f));
    this->buffer->setTireTemperatureRRC(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_REAR_RIGHT][R3E_TIRE_TEMP_CENTER], 0.0f));
    this->buffer->setTireTemperatureRRO(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_REAR_RIGHT][R3E_TIRE_TEMP_RIGHT], 0.0f));

    this->buffer->setTireTemperatureRLI(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_REAR_LEFT][R3E_TIRE_TEMP_RIGHT], 0.0f));
    this->buffer->setTireTemperatureRLC(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_REAR_LEFT][R3E_TIRE_TEMP_CENTER], 0.0f));
    this->buffer->setTireTemperatureRLO(qMax(this->nativeBuffer->tire_temps[R3E_TIRE_REAR_LEFT][R3E_TIRE_TEMP_LEFT], 0.0f));

    this->buffer->setBrakeTemperatureFL(qMax(this->nativeBuffer->brake_temp[R3E_TIRE_FRONT_LEFT], 0.0f));
    this->buffer->setBrakeTemperatureFR(qMax(this->nativeBuffer->brake_temp[R3E_TIRE_FRONT_RIGHT], 0.0f));
    this->buffer->setBrakeTemperatureRR(qMax(this->nativeBuffer->brake_temp[R3E_TIRE_REAR_RIGHT], 0.0f));
    this->buffer->setBrakeTemperatureRL(qMax(this->nativeBuffer->brake_temp[R3E_TIRE_REAR_LEFT], 0.0f));

    this->buffer->setTirePressureFL(qMax(this->nativeBuffer->tire_pressure[R3E_TIRE_FRONT_LEFT], 0.0f) / 100); // Conversion from kPa to Bar
    this->buffer->setTirePressureFR(qMax(this->nativeBuffer->tire_pressure[R3E_TIRE_FRONT_RIGHT], 0.0f) / 100); // Conversion from kPa to Bar
    this->buffer->setTirePressureRR(qMax(this->nativeBuffer->tire_pressure[R3E_TIRE_REAR_RIGHT], 0.0f) / 100); // Conversion from kPa to Bar
    this->buffer->setTirePressureRL(qMax(this->nativeBuffer->tire_pressure[R3E_TIRE_REAR_LEFT], 0.0f) / 100); // Conversion from kPa to Bar

    this->buffer->setTireDirtFL(qMax(this->nativeBuffer->tire_dirt[R3E_TIRE_FRONT_LEFT], 0.0f));
    this->buffer->setTireDirtFR(qMax(this->nativeBuffer->tire_dirt[R3E_TIRE_FRONT_RIGHT], 0.0f));
    this->buffer->setTireDirtRR(qMax(this->nativeBuffer->tire_dirt[R3E_TIRE_REAR_RIGHT], 0.0f));
    this->buffer->setTireDirtRL(qMax(this->nativeBuffer->tire_dirt[R3E_TIRE_REAR_LEFT], 0.0f));

    this->buffer->setCurrentS1(qMax(this->nativeBuffer->sector_time_current_self[0], 0.0f));
    this->buffer->setCurrentS2(qMax(this->nativeBuffer->sector_time_current_self[1], 0.0f));
    this->buffer->setCurrentS3(qMax(this->nativeBuffer->sector_time_current_self[2], 0.0f));

    this->buffer->setBestS1(qMax(this->nativeBuffer->sector_time_best_self[0], 0.0f));
    this->buffer->setBestS2(qMax(this->nativeBuffer->sector_time_best_self[1], 0.0f));
    this->buffer->setBestS3(qMax(this->nativeBuffer->sector_time_best_self[2], 0.0f));

    this->buffer->setPreviousS1(qMax(this->nativeBuffer->sector_time_previous_self[0], 0.0f));
    this->buffer->setPreviousS2(qMax(this->nativeBuffer->sector_time_previous_self[1], 0.0f));
    this->buffer->setPreviousS3(qMax(this->nativeBuffer->sector_time_previous_self[2], 0.0f));

    this->buffer->setTireGripFL(qMax(this->nativeBuffer->tire_grip[R3E_TIRE_FRONT_LEFT], 0.0f));
    this->buffer->setTireGripFR(qMax(this->nativeBuffer->tire_grip[R3E_TIRE_FRONT_RIGHT], 0.0f));
    this->buffer->setTireGripRR(qMax(this->nativeBuffer->tire_grip[R3E_TIRE_REAR_RIGHT], 0.0f));
    this->buffer->setTireGripRL(qMax(this->nativeBuffer->tire_grip[R3E_TIRE_REAR_LEFT], 0.0f));

    this->buffer->setLapDistance(qMax(this->nativeBuffer->lap_distance, 0.0f));

    // Calculate clutchDisengagedTime and gearChangeTime.

    if (!this->shiftTimeData.clutchDisengaged)
    {
        if (this->buffer->getClutch() > 0.03f)
        {
            this->shiftTimeData.clutchDisengagedStart = VRUtilities::getCurrentTime();
            this->shiftTimeData.clutchDisengaged = true;
        }
    }
    else
    {
        if (!this->shiftTimeData.gearChanged && this->buffer->getGear() != this->shiftTimeData.lastGear)
        {
            if (!this->shiftTimeData.changedToNeutral && this->buffer->getGear() == 0)
            {
                this->shiftTimeData.gearChangeStart = VRUtilities::getCurrentTime();
                this->shiftTimeData.changedToNeutral = true;
            }
            else if (this->shiftTimeData.changedToNeutral && this->buffer->getGear() != 0)
            {
                this->shiftTimeData.gearChangeEnd = VRUtilities::getCurrentTime();
                this->shiftTimeData.gearChanged = true;
                this->shiftTimeData.newGear = this->buffer->getGear();
            }
        }
        if (this->buffer->getClutch() < 0.02f)
        {
            this->shiftTimeData.clutchDisengagedEnd = VRUtilities::getCurrentTime();

            if (this->shiftTimeData.gearChanged && this->shiftTimeData.newGear > this->shiftTimeData.lastGear) {
                this->buffer->setClutchDisengagedTime((this->shiftTimeData.clutchDisengagedEnd - this->shiftTimeData.clutchDisengagedStart).count());
                this->buffer->setGearChangeTime((this->shiftTimeData.gearChangeEnd - this->shiftTimeData.gearChangeStart).count());
            }
            this->shiftTimeData = {};
        }
    }

    // all components of accel Behave calculation are updated
    emit this->buffer->accelBehavChanged();

    return true;
}
