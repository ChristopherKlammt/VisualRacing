//
// Created by stark on 21-Oct-17.
//

#include "vrdatainterfaceac.h"

VRDataInterfaceAC::VRDataInterfaceAC() : VRDataInterface(vrconstants::acProcessName) {
    this->accessStatic = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->accessStatic->setNativeKey(vrconstants::acSharedMemoryNameStatic);
    this->nativeBufferStatic = nullptr;

    this->accessPhysics = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->accessPhysics->setNativeKey(vrconstants::acSharedMemoryNamePhysics);
    this->nativeBufferPhysics = nullptr;

    this->accessGraphics = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->accessGraphics->setNativeKey(vrconstants::acSharedMemoryNameGraphcics);
    this->nativeBufferGraphics = nullptr;
}

VRDataInterfaceAC::~VRDataInterfaceAC() {
    this->stop();
}

bool VRDataInterfaceAC::start() {
    // TODO: Print more detailed error descriptions.
    if (this->accessStatic->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferStatic = static_cast<SPageFileStatic*>(this->accessStatic->data());
    else {
        return false;
    }

    if (this->accessPhysics->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferPhysics = static_cast<SPageFilePhysics*>(this->accessPhysics->data());
    else {
        this->accessStatic->detach();
        return false;
    }

    if(this->accessGraphics->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferGraphics = static_cast<SPageFileGraphics*>(this->accessGraphics->data());
    else {
        this->accessStatic->detach();
        this->accessPhysics->detach();
        return false;
    }

    return true;
}

void VRDataInterfaceAC::stop() {
    this->accessStatic->detach();
    this->accessPhysics->detach();
    this->accessGraphics->detach();
}

bool VRDataInterfaceAC::update() {
    if(!this->accessStatic->isAttached() || !this->accessPhysics->isAttached() || !this->accessGraphics->isAttached())
        return false;

    // TODO: Static information like playerName, carName and trackName do not need to be set every update.

    this->buffer->setGear(this->nativeBufferPhysics->gear - 1);
    this->buffer->setVelocity(qMax(this->nativeBufferPhysics->speedKmh, 0.0f));
    this->buffer->setRpm(qMax(this->nativeBufferPhysics->rpms, 0));
    this->buffer->setMaxRpm(qMax(this->nativeBufferStatic->maxRpm, 1));

    // Pedal information:
    this->buffer->setThrottle(qMax(this->nativeBufferPhysics->gas, 0.0f));
    this->buffer->setBrake(qMax(this->nativeBufferPhysics->brake, 0.0f));
    this->buffer->setClutch(qMax(1.0f - this->nativeBufferPhysics->clutch, 0.0f)); // This seems to be the clutch, not the pedal, even though the documentation tells something different.

    this->buffer->setCompletedLaps(this->nativeBufferGraphics->completedLaps);

    this->buffer->setFuel(qMax(this->nativeBufferPhysics->fuel, 0.0f));
    this->buffer->setMaxFuel(qMax(this->nativeBufferStatic->maxFuel, 0.0f));

    this->buffer->setPitLimiter(this->nativeBufferPhysics->pitLimiterOn);
    this->buffer->setIsInPitlane(this->nativeBufferGraphics->isInPitLane);

    this->buffer->setBrakeBias(this->nativeBufferPhysics->brakeBias);

    //this->buffer->setCurrentLapTime();
    //this->buffer->setBestLapTime();
    //this->buffer->setPreviousLapTime();

    /* TODO: Check this behavior. */
    this->buffer->setTireWearFL(qMax(this->nativeBufferPhysics->tyreWear[0], 0.0f) / 100); // Conversion from % to values between 0 and 1
    this->buffer->setTireWearFR(qMax(this->nativeBufferPhysics->tyreWear[1], 0.0f) / 100); // Conversion from % to values between 0 and 1
    this->buffer->setTireWearRR(qMax(this->nativeBufferPhysics->tyreWear[3], 0.0f) / 100); // Conversion from % to values between 0 and 1
    this->buffer->setTireWearRL(qMax(this->nativeBufferPhysics->tyreWear[2], 0.0f) / 100); // Conversion from % to values between 0 and 1

    this->buffer->setTireTemperatureFLI(qMax(this->nativeBufferPhysics->tyreTempO[0], 0.0f));
    this->buffer->setTireTemperatureFLC(qMax(this->nativeBufferPhysics->tyreTempM[0], 0.0f));
    this->buffer->setTireTemperatureFLO(qMax(this->nativeBufferPhysics->tyreTempI[0], 0.0f));

    this->buffer->setTireTemperatureFRI(qMax(this->nativeBufferPhysics->tyreTempI[1], 0.0f));
    this->buffer->setTireTemperatureFRC(qMax(this->nativeBufferPhysics->tyreTempM[1], 0.0f));
    this->buffer->setTireTemperatureFRO(qMax(this->nativeBufferPhysics->tyreTempO[1], 0.0f));

    this->buffer->setTireTemperatureRRI(qMax(this->nativeBufferPhysics->tyreTempI[3], 0.0f));
    this->buffer->setTireTemperatureRRC(qMax(this->nativeBufferPhysics->tyreTempM[3], 0.0f));
    this->buffer->setTireTemperatureRRO(qMax(this->nativeBufferPhysics->tyreTempO[3], 0.0f));

    this->buffer->setTireTemperatureRLI(qMax(this->nativeBufferPhysics->tyreTempO[2], 0.0f));
    this->buffer->setTireTemperatureRLC(qMax(this->nativeBufferPhysics->tyreTempM[2], 0.0f));
    this->buffer->setTireTemperatureRLO(qMax(this->nativeBufferPhysics->tyreTempI[2], 0.0f));

    this->buffer->setBrakeTemperatureFL(qMax(this->nativeBufferPhysics->brakeTemp[0], 0.0f));
    this->buffer->setBrakeTemperatureFR(qMax(this->nativeBufferPhysics->brakeTemp[1], 0.0f));
    this->buffer->setBrakeTemperatureRR(qMax(this->nativeBufferPhysics->brakeTemp[3], 0.0f));
    this->buffer->setBrakeTemperatureRL(qMax(this->nativeBufferPhysics->brakeTemp[2], 0.0f));

    this->buffer->setTirePressureFL(qMax(this->nativeBufferPhysics->wheelsPressure[0], 0.0f) / 14.5038f); // Conversion from psi to Bar
    this->buffer->setTirePressureFR(qMax(this->nativeBufferPhysics->wheelsPressure[1], 0.0f) / 14.5038f); // Conversion from psi to Bar
    this->buffer->setTirePressureRR(qMax(this->nativeBufferPhysics->wheelsPressure[3], 0.0f) / 14.5038f); // Conversion from psi to Bar
    this->buffer->setTirePressureRL(qMax(this->nativeBufferPhysics->wheelsPressure[2], 0.0f) / 14.5038f); // Conversion from psi to Bar

    /* TODO: We get some weird values here. */
    this->buffer->setTireDirtFL(qMax(this->nativeBufferPhysics->tyreDirtyLevel[0], 0.0f));
    this->buffer->setTireDirtFR(qMax(this->nativeBufferPhysics->tyreDirtyLevel[1], 0.0f));
    this->buffer->setTireDirtRR(qMax(this->nativeBufferPhysics->tyreDirtyLevel[3], 0.0f));
    this->buffer->setTireDirtRL(qMax(this->nativeBufferPhysics->tyreDirtyLevel[2], 0.0f));

    // TODO TIMING DATA

    return true;
}
