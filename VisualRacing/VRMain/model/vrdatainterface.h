#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <QSharedMemory>
#include <QSharedPointer>
#include <chrono>

#include "vrdata.h"
#include "vrconstants.h"

class VRDataInterface {
private:
    const wchar_t* processName;
protected:
    QSharedPointer<VRData> buffer;
public:
    VRDataInterface(const wchar_t* processName);
    virtual ~VRDataInterface();

    virtual bool start() = 0;
    virtual void stop() = 0;

    virtual bool update() = 0;

    QSharedPointer<VRData> getBuffer();
    const wchar_t* getProcessName();
};


#endif //DATAINTERFACE_H
