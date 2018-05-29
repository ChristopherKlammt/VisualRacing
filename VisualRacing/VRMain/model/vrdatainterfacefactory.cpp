#include "vrdatainterfacefactory.h"

QSharedPointer<VRDataInterface> VRDataInterfaceFactory::createInterface(Simulation s)
{
    if (s == Simulation::AC)
    {
        return QSharedPointer<VRDataInterface>(new VRDataInterfaceAC());
    }
    else if (s == Simulation::R3E)
    {
        return QSharedPointer<VRDataInterface>(new VRDataInterfaceR3E());
    }
    return nullptr;
}
