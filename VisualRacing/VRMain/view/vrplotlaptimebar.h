#ifndef VRPLOTLAPTIMEBAR_H
#define VRPLOTLAPTIMEBAR_H


#include <QObject>
#include <algorithm>
#include "vrplotitem.h"
#include "vrthemedata.h"

class VRPlotLapTimeBar : public VRPlotItem
{
    Q_OBJECT
public:
    VRPlotLapTimeBar();

    virtual void setupPlot(QCustomPlot* customPlot, VRThemeData* themeData);
    virtual void setTheme(VRThemeData* themeData);

    Q_INVOKABLE void pushData(double lap_time, double sector1, double sector2, double sector3, double best);

public slots:
    void changeLanguage();

private:
    QCPBars* sectorOne;
    QCPBars* sectorTwo;
    QCPBars* sectorThree;

    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> sectorOne_data, sectorTwo_data, sectorThree_data;
    QVector<double> sum_vect;

    int counter;
};

#endif // VRPLOTLAPTIMEBAR_H
