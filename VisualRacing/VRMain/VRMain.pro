QT += quick printsupport
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    qcustomplot.cpp \
    vrconstants.cpp \
    vrmainwindow.cpp \
    vrmessage.cpp \
    vrsettings.cpp \
    vrutilities.cpp \
    model/vrdata.cpp \
    model/vrdatainterface.cpp \
    model/vrdatainterfaceac.cpp \
    model/vrdatainterfacer3e.cpp \
    model/vrsimulationmanager.cpp \
    model/vrmetrics.cpp \
    model/vrmetricsmanager.cpp \
    model/vrdatainterfacefactory.cpp \
    view/vrplotitem.cpp \
    view/vrplotlaptimebar.cpp \
    view/vrplotpedalhistory.cpp \
    view/vrplotpedals.cpp \
    view/vrplotrpm.cpp \
    view/vrplotvelocity.cpp \
    view/vrthemedata.cpp

RESOURCES += qml.qrc \
    translations.qrc \
    resources.qrc

TRANSLATIONS = Deutsch.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    qcustomplot.h \
    vrconstants.h \
    vrmainwindow.h \
    vrmessage.h \
    vrsettings.h \
    vrutilities.h \
    model/ac.h \
    model/r3e.h \
    model/vrdata.h \
    model/vrdatainterface.h \
    model/vrdatainterfaceac.h \
    model/vrdatainterfacer3e.h \
    model/vrsimulationmanager.h \
    model/vrmetrics.h \
    model/vrmetricsmanager.h \
    model/vrdatainterfacefactory.h \
    view/vrplotitem.h \
    view/vrplotlaptimebar.h \
    view/vrplotpedalhistory.h \
    view/vrplotpedals.h \
    view/vrplotrpm.h \
    view/vrplotvelocity.h \
    view/vrthemedata.h
