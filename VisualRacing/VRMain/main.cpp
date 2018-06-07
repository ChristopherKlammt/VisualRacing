#include <string>
#include <QString>
#include <QSharedPointer>
#include <windows.h>

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>

#include "vrmainwindow.h"
#include "vrmessage.h"
#include "vrsettings.h"

#include "view/vrplotvelocity.h"
#include "view/vrplotpedals.h"
#include "view/vrplotlaptimebar.h"
#include "view/vrplotrpm.h"
#include "view/vrplotpedalhistory.h"
#include "view/vrthemedata.h"

#include "model/vrdata.h"
#include "model/vrsimulationmanager.h"
#include "model/vrmetrics.h"
#include "model/vrmetricsmanager.h"


void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
#ifdef Q_OS_WIN32
    const QString newLine = "\r\n";
#else
    const QString newLine = "\n";
#endif

    QTextStream out(stderr);

    const auto srcFile = QString("%1").arg(context.function, -70, QChar(' '));
    const auto typeStr = [type]() -> QString {
        switch (type) {
        case QtInfoMsg: return QStringLiteral("INFO:     ");
        case QtDebugMsg: return QStringLiteral("DEBUG:    ");
        case QtWarningMsg: return QStringLiteral("WARNING:  ");
        case QtCriticalMsg: return QStringLiteral("CRITICAL: ");
        case QtFatalMsg: return QStringLiteral("FATAL:    ");
        default: return QStringLiteral("UNKNOWN:  ");
        }
    }();

    out << "[" << srcFile << "] " << typeStr << msg.toLocal8Bit() << newLine;

    if (type == QtFatalMsg) {
        abort();
    }
}

int main(int argc, char *argv[])
{
    // Load settings and set theme.
    VRSettings settings;
    VRThemeData themeData(settings.getTheme());

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/icon.ico"));

    qInstallMessageHandler(messageHandler);

    QSharedPointer<QQmlApplicationEngine> engine(new QQmlApplicationEngine);
    QScopedPointer<VRMainWindow> mainWindow(new VRMainWindow);
    QSharedPointer<VRSimulationManager> simulationManager;
    QSharedPointer<VRData> vrData;

    mainWindow.data()->setEngine(engine);
    mainWindow.data()->switchLanguage(settings.getLang());

    bool uiDev = true;
    if (!uiDev) {
        simulationManager = QSharedPointer<VRSimulationManager>(new VRSimulationManager());
        simulationManager->start();

        QSharedPointer<VRDataInterface> dataInterface;
        do {
            dataInterface = simulationManager->getDataInterface();
        } while(dataInterface.isNull());

        vrData = dataInterface->getBuffer();

        QSharedPointer<VRMessage> connectedMessage = QSharedPointer<VRMessage>(new VRMessage(QString(QObject::tr("DataInterface connected successfully.")), QColor(38, 211, 67)));
        mainWindow->setItsCurrentMessage(connectedMessage);
    } else {
        vrData = QSharedPointer<VRData>(new VRData());

        QSharedPointer<VRMessage> devMessage = QSharedPointer<VRMessage>(new VRMessage(QString(QObject::tr("Ui-Development-Mode active.")), QColor(239, 105, 9)));
        mainWindow->setItsCurrentMessage(devMessage);
    }

    /*
     * start Metrics calculation
     */
    QSharedPointer<VRMetrics> vrMetrics;
    QSharedPointer<VRMetricsManager> vrMetricsManager;

    vrMetrics = QSharedPointer<VRMetrics>(new VRMetrics());
    vrMetricsManager = QSharedPointer<VRMetricsManager>(
                new VRMetricsManager(vrMetrics, vrData));

    QThread* metricsManagerThread = new QThread;
    vrMetricsManager->moveToThread(metricsManagerThread);
    metricsManagerThread->start();

    /*
     * expose Data-Objects to qml
     */
    engine->rootContext()->setContextProperty("vrMainWindow", mainWindow.data());
    engine->rootContext()->setContextProperty("vrData", vrData.data());
    engine->rootContext()->setContextProperty("settings", &settings);
    engine->rootContext()->setContextProperty("theme", &themeData);
    engine->rootContext()->setContextProperty("vrMetrics", vrMetrics.data());

    /*
     * QML-Type Registration
     */
    qmlRegisterType<VRPlotVelocity>("VRPlot", 1, 0, "VRPlotVelocity");
    qmlRegisterType<VRPlotPedals>("VRPlot", 1, 0, "VRPlotPedals");
    qmlRegisterType<VRPlotLapTimeBar>("VRPlot", 1, 0, "VRPlotLapTimeBar");
    qmlRegisterType<VRPlotRPM>("VRPlot", 1, 0, "VRPlotRPM");
    qmlRegisterType<VRPlotPedalHistory>("VRPlot", 1, 0, "VRPlotPedalHistory");
    qmlRegisterType<VRSettings>("VRSettings", 1, 0, "VRSettings");
    qmlRegisterType<VRMetrics>("VRMetrics", 1, 0, "VRMetrics");

    /*
     * load qml-file
     */
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine->rootObjects().isEmpty())
        return EXIT_FAILURE;
    int retVal = app.exec();

    return retVal;
}

