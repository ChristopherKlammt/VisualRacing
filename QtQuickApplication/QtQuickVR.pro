QT += quick printsupport
CONFIG += c++11

# LIBS += -lglu32

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    vrmessage.cpp \
    vrmainwindow.cpp \
    qcustomplot.cpp \
    vrutilities.cpp \
    vrconstants.cpp \
    model/vrdata.cpp \
    model/vrdatainterface.cpp \
    model/vrdatainterfaceac.cpp \
    model/vrdatainterfacer3e.cpp \
    model/vrsimulationmanager.cpp \
    view/vrplotitem.cpp \
    view/vrplotlaptimebar.cpp \
    view/vrplotpedalhistory.cpp \
    view/vrplotpedals.cpp \
    view/vrplotrpm.cpp \
    view/vrplotvelocity.cpp \
    main.cpp \
    vrsettings.cpp \
    view/vrthemedata.cpp \
    model/vrmetrics.cpp \
    model/vrmetricsmanager.cpp

TRANSLATIONS = Deutsch.ts

RESOURCES += qml.qrc resources.qrc \
    translations.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    vrmessage.h \
    vrmainwindow.h \
    qcustomplot.h \
    vrutilities.h \
    vrconstants.h \
    model/ac.h \
    model/r3e.h \
    model/vrdata.h \
    model/vrdatainterface.h \
    model/vrdatainterfaceac.h \
    model/vrdatainterfacer3e.h \
    model/vrsimulationmanager.h \
    view/vrplotitem.h \
    view/vrplotlaptimebar.h \
    view/vrplotpedalhistory.h \
    view/vrplotpedals.h \
    view/vrplotrpm.h \
    view/vrplotvelocity.h \
    vrsettings.h \
    view/vrthemedata.h \
    model/vrmetrics.h \
    model/vrmetricsmanager.h
