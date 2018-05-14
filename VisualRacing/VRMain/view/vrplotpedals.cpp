#include "vrplotpedals.h"

VRPlotPedals::VRPlotPedals() : VRPlotItem()
{

}

void VRPlotPedals::pushData(double clutch, double brake, double accel)
{
    QVector<double> ticks_vect_clutch;
    QVector<double> ticks_vect_brak;
    QVector<double> ticks_vect_acc;
    ticks_vect_clutch << 1;
    ticks_vect_brak << 2;
    ticks_vect_acc << 3;

    QVector<double> clutch_data, brake_data, accel_data;
    clutch_data << clutch;
    brake_data << brake;
    accel_data << accel;

    clutchPedal->setData(ticks_vect_clutch, clutch_data);
    brakePedal->setData(ticks_vect_brak, brake_data);
    accelPedal->setData(ticks_vect_acc, accel_data);

    itsCustomPlot->replot();
}

void VRPlotPedals::setTheme(VRThemeData *themeData)
{
    QColor lineColor(themeData->getAccentColor());

    itsCustomPlot->xAxis->setBasePen(QPen(lineColor));
    itsCustomPlot->xAxis->setTickPen(QPen(lineColor));
    itsCustomPlot->xAxis->grid()->setPen(QPen(lineColor, 0, Qt::DotLine));
    itsCustomPlot->xAxis->setTickLabelColor(lineColor);
    itsCustomPlot->xAxis->setLabelColor(lineColor);


    itsCustomPlot->yAxis->setBasePen(QPen(lineColor));
    itsCustomPlot->yAxis->setTickPen(QPen(lineColor));
    itsCustomPlot->yAxis->setSubTickPen(QPen(lineColor));
    itsCustomPlot->yAxis->setTickLabelColor(lineColor);
    itsCustomPlot->yAxis->setLabelColor(lineColor);
    itsCustomPlot->yAxis->grid()->setPen(QPen(lineColor, 0, Qt::SolidLine));
    itsCustomPlot->yAxis->grid()->setSubGridPen(QPen(lineColor, 0, Qt::DotLine));

    itsCustomPlot->setBackground(QBrush(QColor(themeData->getTabBackgroundColor())));

    itsCustomPlot->replot();
}

void VRPlotPedals::setupPlot(VRThemeData* themeData)
{
    // init QCPBars
    clutchPedal = new QCPBars(itsCustomPlot->xAxis, itsCustomPlot->yAxis);
    accelPedal = new QCPBars(itsCustomPlot->xAxis, itsCustomPlot->yAxis);
    brakePedal = new QCPBars(itsCustomPlot->xAxis, itsCustomPlot->yAxis);

    // set Names and Colors
    clutchPedal->setName(tr("Clutch Pedal"));
    clutchPedal->setPen(QPen(QColor(57, 78, 173).lighter(170)));
    clutchPedal->setBrush(QColor(57, 78, 173));

    brakePedal->setName(tr("Brake Pedal"));
    brakePedal->setPen(QPen(QColor(173, 57, 84).lighter(170)));
    brakePedal->setBrush(QColor(173, 57, 84));

    accelPedal->setName(tr("Acceleration Pedal"));
    accelPedal->setPen(QPen(QColor(61, 173, 57).lighter(170)));
    accelPedal->setBrush(QColor(61, 173, 57));

    // prepare x axis with names
    ticks_vect << 1 << 2 << 3;
    labels_vect << tr("Clutch") << tr("Brake") << tr("Throttle");

    // prepare x axis:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks_vect, labels_vect);
    itsCustomPlot->xAxis->setTicker(textTicker);
    //itsCustomPlot->xAxis->setTickLabelRotation(60);
    itsCustomPlot->xAxis->setSubTicks(false);
    itsCustomPlot->xAxis->setTickLength(0, 4);
    itsCustomPlot->xAxis->setRange(0, 4);
    itsCustomPlot->xAxis->grid()->setVisible(true);

    // prepare y axis:
    itsCustomPlot->yAxis->setRange(0, 1);
    itsCustomPlot->yAxis->setPadding(5); // a bit more space to the left border
    itsCustomPlot->yAxis->setLabel(tr("Mechanical deflection"));
    itsCustomPlot->yAxis->grid()->setSubGridVisible(true);

    // connect mouse interaction
    //itsCustomPlot ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables );
    itsCustomPlot ->setInteractions( QCP::iSelectPlottables );
    connect( itsCustomPlot, SIGNAL( plottableClick( QCPAbstractPlottable*, int,  QMouseEvent* ) ), this, SLOT( graphClicked( QCPAbstractPlottable* ) ) );

    // set theme (also does a replot-call)
    setTheme(themeData);
}

void VRPlotPedals::changeLanguage()
{
    itsCustomPlot->yAxis->setLabel(tr("Mechanical deflection"));

    labels_vect.clear();
    labels_vect << tr("Clutch") << tr("Brake") << tr("Throttle");
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks_vect, labels_vect);
    itsCustomPlot->xAxis->setTicker(textTicker);

    update();
}

