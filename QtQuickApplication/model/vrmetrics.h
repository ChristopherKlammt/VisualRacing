#ifndef VRMETRICS_H
#define VRMETRICS_H

#include <QObject>

class VRMetrics : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float upShiftBehaviour READ getUpShiftBehaviour WRITE setUpShiftBehaviour NOTIFY upShiftBehaviourChanged)

public:
    VRMetrics();
    ~VRMetrics();

    float getUpShiftBehaviour() const;
    void setUpShiftBehaviour(float upShiftBehaviour);

signals:
    void upShiftBehaviourChanged();

private:
    float upShiftBehaviour;

};

#endif // VRMETRICS_H
