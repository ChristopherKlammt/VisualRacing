//
// Created by stark on 21-Oct-17.
//

#include "vrdatainterfaceac.h"

VRDataInterfaceAC::VRDataInterfaceAC() : VRDataInterface(vrconstants::acProcessName) {
    this->accessStatic = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->accessStatic->setNativeKey(vrconstants::acSharedMemoryNameStatic);

    this->accessPhysics = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->accessPhysics->setNativeKey(vrconstants::acSharedMemoryNamePhysics);

    this->accessGraphics = QSharedPointer<QSharedMemory>(new QSharedMemory());
    this->accessGraphics->setNativeKey(vrconstants::acSharedMemoryNameGraphcics);
}

VRDataInterfaceAC::~VRDataInterfaceAC() {
    this->stop();
}

bool VRDataInterfaceAC::start() {
    // TODO: Print more detailed error descriptions.
    if (this->accessStatic->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferStatic = (SPageFileStatic*)this->accessStatic->data();
    else {
        return false;
    }

    if (this->accessPhysics->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferPhysics = (SPageFilePhysics*)this->accessPhysics->data();
    else {
        this->accessStatic->detach();
        return false;
    }

    if(this->accessGraphics->attach(QSharedMemory::AccessMode::ReadOnly))
        this->nativeBufferGraphics = (SPageFileGraphics*)this->accessGraphics->data();
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


    return true;
}
