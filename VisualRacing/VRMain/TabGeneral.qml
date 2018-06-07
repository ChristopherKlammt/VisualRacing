import QtQuick 2.0
import VRPlot 1.0
import QtQuick.Layouts 1.3
import VRSettings 1.0

Rectangle {

    Connections {
        target: settings
        onLangChanged: {
            rpmPlot.changeLanguage();
            pedalHistoryPlot.changeLanguage();
            pedalsPlot.changeLanguage();
            velocityPlot.changeLanguage();
        }
     }

    color: theme.tabBackgroundColor

    VRPlotRPM {
        id: rpmPlot
        objectName: "rpmPlot"
        width: parent.width / 3
        height: parent.height * 0.5
        anchors.top: parent.top
        anchors.left: parent.left

        Component.onCompleted: init()

        function init(){
            rpmPlot.initCustomPlot(theme);
            rpmPlot.setItsMaxRpm(6000);
        }

        Timer {
            interval: 20
            running: true
            repeat: true
            onTriggered: rpmPlot.pushData(vrData.getTimeInSeconds(), vrData.rpm, vrData.gear)
        }

        Connections {
            target: vrData
            onMaxRpmChanged: rpmPlot.setItsMaxRpm(vrData.maxRpm)
        }

        Connections {
            target: theme
            onThemeChanged: rpmPlot.setTheme(theme)
        }
    }

    ////////////////////////////////////////////////////////////////////////
    Rectangle {
        id: generalInfoTile
        width: parent.width * 0.25
        height: parent.height * 0.42
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 15

        color: "transparent"
        border.color: theme.accentColor

        Rectangle {
            id: revCounterContainer
            width: parent.width * 0.9
            height: parent.height * 0.15
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 15

            color: theme.appBackgroundColor;

            Rectangle {
                id: revCounter
                width: parent.width * (vrData.rpm / vrData.maxRpm)
                height: parent.height
                anchors.top: parent.top
                anchors.left: parent.left

                color: (vrData.rpm / vrData.maxRpm) > 0.9 ? "red" : "lime"
            }
        }

        Text {
            id: gearLabel
            text: gearIndexToChar(vrData.gear)
            color: theme.textColor
            
            anchors.centerIn: parent
            width: parent.width * 0.4
            height: parent.height * 0.7

            font {
                pointSize: 500
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: velocityLabel
            text: returnVelocity(vrData.velocity)
            color: theme.textColor
            
            anchors.right: gearLabel.left
            anchors.bottom: parent.verticalCenter

            width: parent.width * 0.25
            height: parent.height * 0.25

            font {
                pointSize: 100
            }

            minimumPointSize: 2
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: velocityUnitDesc
            text: settings.unit == VRSettings.METRIC ? qsTr("km/h") + vrMainWindow.emptyString : qsTr("mph") + vrMainWindow.emptyString
            color: theme.textColor
            
            anchors.right: gearLabel.left
            anchors.top: parent.verticalCenter

            width: parent.width * 0.15
            height: parent.height * 0.25

            font {
                pointSize: 100
            }

            minimumPointSize: 2
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignTop
        }


        Text {
            id: rpmLabel
            text: vrData.rpm
            color: theme.textColor
            
            anchors.right: parent.right
            anchors.bottom: parent.verticalCenter
            anchors.rightMargin: 10

            width: parent.width * 0.25
            height: parent.height * 0.25

            font {
                pointSize: 100
            }

            minimumPointSize: 2
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            text: "RPM"
            color: theme.textColor
            
            anchors.right: parent.right
            anchors.top: parent.verticalCenter
            anchors.rightMargin: 10

            width: parent.width * 0.15
            height: parent.height * 0.25

            font.pointSize: velocityUnitDesc.fontInfo.pointSize

            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignTop
        }

        Row {
            id: statusRow
            anchors.bottom: generalInfoTile.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height * 0.25

            Rectangle {
                id: status1
                height: parent.height
                width: parent.width * 0.25

                color: "transparent"
                border.color: theme.accentColor

                Text {
                    width: parent.width
                    anchors.centerIn: parent
                    horizontalAlignment: Text.Center

                    wrapMode: Text.WordWrap
                    font.pixelSize: parent.height * 0.3
                    color: (false ? "lime" : "#798489") // COL

                    text: "-"
                }
            }

            Rectangle {
                id: status2
                height: parent.height
                width: parent.width * 0.25

                color: "transparent"
                border.color: theme.accentColor

                Text {
                    width: parent.width
                    anchors.centerIn: parent
                    horizontalAlignment: Text.Center

                    wrapMode: Text.WordWrap
                    font.pixelSize: parent.height * 0.3
                    color: (false ? "lime" : "#798489") // COL

                    text: "-"
                }
            }

            Rectangle {
                id: status3
                height: parent.height
                width: parent.width * 0.25

                color: "transparent"
                border.color: theme.accentColor

                Text {
                    width: parent.width
                    anchors.centerIn: parent
                    horizontalAlignment: Text.Center

                    wrapMode: Text.WordWrap
                    font.pixelSize: parent.height * 0.3
                    color: (vrData.pitLimiter ? "lime" : "#798489") // COL

                    text: qsTr("Pit Limiter") + vrMainWindow.emptyString
                }
            }

            Rectangle {
                id: status4
                height: parent.height
                width: parent.width * 0.25

                color: "transparent"
                border.color: theme.accentColor

                Text {
                    width: parent.width
                    anchors.centerIn: parent
                    horizontalAlignment: Text.Center

                    wrapMode: Text.WordWrap
                    font.pixelSize: parent.height * 0.3
                    color: (vrData.isInPitlane ? "lime" : "#798489") // COL

                    text: qsTr("In Pitlane") + vrMainWindow.emptyString
                }
            }
        }
    }
    //////////////////////////////////////////////////////////////////////

    VRPlotVelocity {
        id: velocityPlot
        objectName: "velocityPlot"
        width: parent.width / 3
        height: parent.height * 0.5
        anchors.right: parent.right
        anchors.top: parent.top

        Component.onCompleted: initCustomPlot(theme)

        Timer {
            interval: 20
            running: true
            repeat: true
            onTriggered: velocityPlot.pushData(vrData.getTimeInSeconds(), vrData.velocity)
        }

        Connections {
            target: theme
            onThemeChanged: velocityPlot.setTheme(theme)
        }
    }

    VRPlotPedalHistory {
        id: pedalHistoryPlot
        width: parent.width * 0.25
        height: parent.height * 0.5
        anchors.left: parent.left
        anchors.bottom: parent.bottom

        Component.onCompleted: initCustomPlot(theme)

        Connections {
            target: theme
            onThemeChanged: pedalHistoryPlot.setTheme(theme)
        }
    }

    VRPlotPedals {
        id: pedalsPlot
        width: parent.width * 0.25
        height: parent.height * 0.5
        anchors.left: pedalHistoryPlot.right
        anchors.bottom: parent.bottom

        Component.onCompleted: initCustomPlot(theme)

        Connections {
            target: vrData
            onThrottleChanged: update(vrData.throttle, vrData.brake, vrData.clutch)
            onBrakeChanged: update(vrData.throttle, vrData.brake, vrData.clutch)
            onClutchChanged: update(vrData.throttle, vrData.brake, vrData.clutch)

            function update(throttle, brake, clutch) {
                pedalsPlot.pushData(clutch, brake, throttle);
            }
        }

        Connections {
            target: theme
            onThemeChanged: pedalsPlot.setTheme(theme)
        }

        Timer {
            interval: 20
            running: true
            repeat: true
            onTriggered: pedalHistoryPlot.pushData(vrData.getTimeInSeconds(), vrData.clutch, vrData.brake, vrData.throttle)
        }
    }

    Rectangle {
        id: laptimeOverview
        width: parent.width * 0.25 -30
        height: parent.height * 0.47
        anchors.left: pedalsPlot.right
        anchors.bottom: parent.bottom
        anchors.margins: 15

        color: "transparent"
        border.color: theme.accentColor

        Text {
            id: lapsTitle
            text: qsTr("Laptimes") + vrMainWindow.emptyString
            color: theme.textColor

            font.pixelSize: (laptimeOverview.width * 0.2) * (laptimeOverview.height * 0.2) * 0.0075;

            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 5
        }

        GridLayout {
            columns: 2
            anchors.centerIn: parent

            Text {
                id: currentLapLabel
                text: qsTr("Current:") + vrMainWindow.emptyString
                color: theme.textColor
                Layout.rightMargin: 20
                Layout.bottomMargin: 10

                font.pixelSize: ((laptimeOverview.width - 25) * 0.15) * ((laptimeOverview.height - 25) * 0.15) * 0.01;
            }

            Text {
                id: currentLapValue
                text: lapTimeToString(vrData.currentLapTime)
                color: theme.textColor
                Layout.bottomMargin: 10

                font.bold: true
                font.pixelSize: currentLapLabel.font.pixelSize
            }

            Text {
                id: lastLapLabel
                text: qsTr("Last:") + vrMainWindow.emptyString
                color: theme.textColor
                Layout.rightMargin: 20
                Layout.bottomMargin: 10

                font.pixelSize: currentLapLabel.font.pixelSize
            }

            Text {
                id: lastLapValue
                text: lapTimeToString(vrData.previousLapTime)
                color: theme.textColor
                Layout.bottomMargin: 10

                font.bold: true
                font.pixelSize: currentLapLabel.font.pixelSize
            }

            Text {
                id: bestLapLabel
                text: qsTr("Best:") + vrMainWindow.emptyString
                color: theme.textColor
                Layout.rightMargin: 20
                Layout.bottomMargin: 10

                font.pixelSize: currentLapLabel.font.pixelSize
            }

            Text {
                id: bestLapValue
                text: lapTimeToString(vrData.bestLapTime)
                color: theme.textColor
                Layout.bottomMargin: 10

                font.bold: true
                font.pixelSize: currentLapLabel.font.pixelSize
            }
        }
    }

    Rectangle {
        id: tireOverview
        width: parent.width * 0.25 - 30
        height: parent.height * 0.47
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 15

        color: "transparent"
        border.color: theme.accentColor

        Rectangle{
            id: frontLeftBox
            width: parent.width * 0.23
            height: parent.height * 0.30
            anchors.top: parent.top
            anchors.left: parent.left
            color: "transparent"

            anchors.leftMargin: parent.width * 0.1
            anchors.topMargin: parent.height * 0.1

            Rectangle{
                id: frontLeft
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: tempToColor(vrData.tireTemperatureFLI) }
                    GradientStop { position: 0.5; color: tempToColor(vrData.tireTemperatureFLC) }
                    GradientStop { position: 1.0; color: tempToColor(vrData.tireTemperatureFLO) }
                }

            }
        }

        Rectangle {
            id: frontLeftState
            width: parent.width * 0.07
            height: frontLeftBox.height
            anchors.top: frontLeftBox.top
            anchors.left: frontLeftBox.right
            anchors.leftMargin: parent.width * 0.02

            color: theme.appBackgroundColor;
            border.color: percToColor(vrData.tireWearFL)

            Rectangle {
                width: parent.width
                height: parent.height * vrData.tireWearFL
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                color: percToColor(vrData.tireWearFL)
            }
        }

        Rectangle{
            id: frontRightBox
            width: parent.width * 0.23
            height: parent.height * 0.30
            anchors.top: parent.top
            anchors.right: parent.right
            color: "transparent"

            anchors.rightMargin: parent.width * 0.1
            anchors.topMargin: parent.height * 0.1

            Rectangle{
                id: frontRight
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: tempToColor(vrData.tireTemperatureFRO) }
                    GradientStop { position: 0.5; color: tempToColor(vrData.tireTemperatureFRC) }
                    GradientStop { position: 1.0; color: tempToColor(vrData.tireTemperatureFRI) }
                }

            }
        }

        Rectangle {
            id: frontRightState
            width: parent.width * 0.07
            height: frontRightBox.height
            anchors.top: frontRightBox.top
            anchors.right: frontRightBox.left
            anchors.rightMargin: parent.width * 0.02

            color: theme.appBackgroundColor;
            border.color: percToColor(vrData.tireWearFR)

            Rectangle {
                width: parent.width
                height: parent.height * vrData.tireWearFR
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                color: percToColor(vrData.tireWearFR)
            }
        }

        Rectangle{
            id: rearLeftBox
            width: parent.width * 0.23
            height: parent.height * 0.30
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            color: "transparent"

            anchors.leftMargin: parent.width * 0.1
            anchors.bottomMargin: parent.height * 0.1

            Rectangle{
                id: rearLeft
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: tempToColor(vrData.tireTemperatureRLI) }
                    GradientStop { position: 0.5; color: tempToColor(vrData.tireTemperatureRLC) }
                    GradientStop { position: 1.0; color: tempToColor(vrData.tireTemperatureRLO) }
                }

            }
        }

        Rectangle {
            id: rearLeftState
            width: parent.width * 0.07
            height: rearLeftBox.height
            anchors.top: rearLeftBox.top
            anchors.left: rearLeftBox.right
            anchors.leftMargin: parent.width * 0.02

            color: theme.appBackgroundColor;
            border.color: percToColor(vrData.tireWearRL)

            Rectangle {
                width: parent.width
                height: parent.height * vrData.tireWearRL
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                color: percToColor(vrData.tireWearRL)
            }
        }

        Rectangle{
            id: rearRightBox
            width: parent.width * 0.23
            height: parent.height * 0.30
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            color: "transparent"

            anchors.rightMargin: parent.width * 0.1
            anchors.bottomMargin: parent.height * 0.1

            Rectangle{
                id: rearRight
                width: parent.height
                height: parent.width
                anchors.centerIn: parent
                rotation: 90
                radius: 17

                gradient: Gradient {
                    GradientStop { position: 0.0; color: tempToColor(vrData.tireTemperatureRRO) }
                    GradientStop { position: 0.5; color: tempToColor(vrData.tireTemperatureRRC) }
                    GradientStop { position: 1.0; color: tempToColor(vrData.tireTemperatureRRI) }
                }
            }
        }

        Rectangle {
            id: rearRightState
            width: parent.width * 0.07
            height: rearRightBox.height
            anchors.top: rearRightBox.top
            anchors.right: rearRightBox.left
            anchors.rightMargin: parent.width * 0.02

            color: theme.appBackgroundColor;
            border.color: percToColor(vrData.tireWearRR)

            Rectangle {
                width: parent.width
                height: parent.height * vrData.tireWearRR
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                color: percToColor(vrData.tireWearRR)
            }
        }
    }
}
