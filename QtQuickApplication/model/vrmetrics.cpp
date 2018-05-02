#include "vrmetrics.h"

VRMetrics::VRMetrics()
{
    this->upShiftBehaviour = 0;
}

VRMetrics::~VRMetrics()
{

}

float VRMetrics::getUpShiftBehaviour() const
{
    return this->upShiftBehaviour;
}

void VRMetrics::setUpShiftBehaviour(float upShiftBehaviour)
{
    this->upShiftBehaviour = upShiftBehaviour;
    emit upShiftBehaviourChanged();
}
