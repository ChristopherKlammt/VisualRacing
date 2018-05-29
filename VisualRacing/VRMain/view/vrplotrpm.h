#ifndef VRPLOTRPM_H
#define VRPLOTRPM_H

#include <QObject>
#include "vrplotitem.h"
#include "vrthemedata.h"

class VRPlotRPM : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotRPM();

    virtual void setupPlot( QCustomPlot* customPlot, VRThemeData* themeData);
    Q_INVOKABLE void setItsMaxRpm(int maxRpm);
    Q_INVOKABLE void pushData(double index, double data, int gear);
    virtual void setTheme(VRThemeData* themeData);

public slots:
    void changeLanguage();

private:
    int itsMaxRpm;
    double itsGearMultiplier;

    int itsLastGear;
    double itsLastGearDouble;

};

#endif // VRPLOTRPM_H
