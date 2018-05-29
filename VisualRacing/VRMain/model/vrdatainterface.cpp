#include "vrdatainterface.h"

VRDataInterface::VRDataInterface(const wchar_t* processName) {
    this->processName = processName;
    this->buffer = QSharedPointer<VRData>(new VRData());
}

VRDataInterface::~VRDataInterface() {
}

QSharedPointer<VRData> VRDataInterface::getBuffer() {
    return this->buffer;
}

const wchar_t* VRDataInterface::getProcessName() {
    return this->processName;
}
