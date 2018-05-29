#include "vrplotrpm.h"

VRPlotRPM::VRPlotRPM()
{
    this->itsMaxRpm = 8000;
    this->itsGearMultiplier = 1;
    this->itsLastGear = 0;
    this->itsLastGearDouble = 0.0;
}

void VRPlotRPM::pushData(double index, double data, int gear)
{
    // push data to graph
    if(gear != itsLastGear){
        itsLastGear = gear;
        itsLastGearDouble = (gear * itsGearMultiplier) + (2 * itsGearMultiplier);
    }
    itsCustomPlot->graph(0)->addData(index, itsLastGearDouble);

    itsCustomPlot->graph(1)->addData(index, data);

    // make index axis range scroll with the data (at a constant range size of 10):
    itsCustomPlot->xAxis->setRange(index, 10, Qt::AlignRight);
    itsCustomPlot->replot();
}

void VRPlotRPM::setItsMaxRpm(int maxRpm)
{
    this->itsMaxRpm = maxRpm;
    this->itsGearMultiplier = itsMaxRpm / 9;           // 8 gears
    this->itsLastGearDouble = 2 * itsGearMultiplier;
    itsCustomPlot->yAxis->setRange(0, itsMaxRpm);
    itsCustomPlot->replot();
}

void VRPlotRPM::setTheme(VRThemeData* themeData)
{
    QColor lineColor(themeData->getAccentColor());

    itsCustomPlot->xAxis->setBasePen(QPen(lineColor));
    itsCustomPlot->xAxis->setTickPen(QPen(lineColor));
    itsCustomPlot->xAxis->setSubTickPen(QPen(lineColor));
    itsCustomPlot->xAxis->setTickLabelColor(lineColor);
    itsCustomPlot->xAxis->setLabelColor(lineColor);
    itsCustomPlot->xAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

    itsCustomPlot->yAxis->setBasePen(QPen(lineColor));
    itsCustomPlot->yAxis->setTickPen(QPen(lineColor));
    itsCustomPlot->yAxis->setSubTickPen(QPen(lineColor));
    itsCustomPlot->yAxis->setTickLabelColor(lineColor);
    itsCustomPlot->yAxis->setLabelColor(lineColor);
    itsCustomPlot->yAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));

    itsCustomPlot->setBackground(QBrush(QColor(themeData->getTabBackgroundColor())));

    itsCustomPlot->replot();
}

void VRPlotRPM::setupPlot(QCustomPlot *customPlot, VRThemeData* themeData)
{
    // add graph
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(QColor("#10ff10"), qreal(2.0)));
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(QColor("#ffa500"), qreal(2.0)));

    // set axis labels
    customPlot->xAxis->setLabel(tr("Time in s"));
    customPlot->yAxis->setLabel(tr("RPM / gear"));

    // configure xAxis
    customPlot->xAxis->setRange(0, 10);

    // cofigure yAxis
    customPlot->yAxis->setRange(0, itsMaxRpm);

    // set theme (also does a replot-call)
    setTheme(themeData);
}


void VRPlotRPM::changeLanguage()
{
    itsCustomPlot->xAxis->setLabel(tr("Time in s"));
    itsCustomPlot->yAxis->setLabel(tr("RPM / gear"));

    update();
}
