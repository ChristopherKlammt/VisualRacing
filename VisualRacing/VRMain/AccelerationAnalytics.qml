import QtQuick 2.0

Rectangle {
    color: theme.appBackgroundColor

    Text {
        id: accelBehavTitle
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.leftMargin: 15
        anchors.rightMargin: 15
        width: parent.width - 30

        color: theme.tabBackgroundColor
        text: qsTr("Acceleration") + vrMainWindow.emptyString

        font {
            pointSize: 50
            bold: true
        }
        minimumPointSize: 2
        fontSizeMode: Text.Fit
    }

    Rectangle {
        id: accelAdvice
        width: parent.width
        height: parent.height * 0.35
        anchors.left: parent.left
        anchors.top: parent.top

        color: "transparent"

        Text {
            id: accelAdviceText
            color: theme.textColor
            text: "-"

            anchors.fill: parent

            font {
                pointSize: 40
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Connections {
            target: vrMetrics
            onAccelBehavChanged: accelAdvice.updateText()
        }

        function updateText() {
            if (vrMetrics.accelBehav === VRMetrics.GOOD)
                accelAdviceText.text = "Good";
            else if (vrMetrics.accelBehav === VRMetrics.MORE_THROTTLE)
                accelAdviceText.text = "More throttle";
            else if (vrMetrics.accelBehav === VRMetrics.LESS_THROTTLE)
                accelAdviceText.text = "Less throttle";
            else if (vrMetrics.accelBehav === VRMetrics.UPSHIFT)
                    accelAdviceText.text = "Upshift";
            else if (vrMetrics.accelBehav === VRMetrics.DOWNSHIFT)
                accelAdviceText.text = "Downshift";
            else
                accelAdviceText.text = "-"

        }
    }

    Rectangle {
        id: classificationContainer
        width: parent.width
        height: parent.height * 0.25
        anchors.left: parent.left
        anchors.top: accelAdvice.bottom

        color: "transparent"

        Text {
            id: classificationHeader
            color: theme.textColor
            text: qsTr("Current classification") + vrMainWindow.emptyString

            height: parent.height * 0.2
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 5

            font {
                pointSize: 50
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: throttleClassification
            color: theme.textColor
            text: "-"

            anchors.left: parent.left
            anchors.top: classificationHeader.bottom
            anchors.margins: 10

            font {
                pointSize: 14
            }
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: rpmClassification
            color: theme.textColor
            text: "-"

            anchors.left: parent.left
            anchors.top: throttleClassification.bottom
            anchors.margins: 10

            font {
                pointSize: 14
            }
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: gripClassification
            color: theme.textColor
            text: "-"

            anchors.left: parent.left
            anchors.top: rpmClassification.bottom
            anchors.margins: 10

            font {
                pointSize: 14
            }
            verticalAlignment: Text.AlignVCenter
        }

        Connections {
            target: vrMetrics
            onThrottleClassificationChanged: classificationContainer.updateThrottleClassificationText()
            onRpmClassificationChanged: classificationContainer.updateRpmClassificationText()
            onGripClassificationChanged: classificationContainer.updateGripClassificationText()
        }

        function updateThrottleClassificationText() {
            if (vrMetrics.throttleClassification === VRMetrics.MAX)
                throttleClassification.text = "Max throttle";
            else if (vrMetrics.throttleClassification === VRMetrics.MED2HIGH)
                throttleClassification.text = "Med-High throttle";
            else if (vrMetrics.throttleClassification === VRMetrics.LOW2MED)
                throttleClassification.text = "Low-Med throttle";
            else
                throttleClassification.text = "-";
        }

        function updateRpmClassificationText() {
            if (vrMetrics.rpmClassification === VRMetrics.HIGH)
                rpmClassification.text = "High RPM";
            else if (vrMetrics.rpmClassification === VRMetrics.LOW_MED)
                rpmClassification.text = "Low-Med RPM";
            else
                rpmClassification.text = "-";
        }

        function updateGripClassificationText() {
            if (vrMetrics.gripClassification === VRMetrics.FULL)
                gripClassification.text = "Full grip";
            else if (vrMetrics.gripClassification === VRMetrics.LOOSING)
                gripClassification.text = "Loosing grip";
            else
                gripClassification.text = "-";
        }
    }

    Rectangle {
        id: gripContainer
        anchors.left: parent.left
        anchors.top: classificationContainer.bottom
        anchors.bottom: accelBehavTitle.top
        width: parent.width

        color: theme.appBackgroundColor

        Rectangle {
            id: frontLeft
            anchors.left: parent.left
            anchors.top: parent.top
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.leftMargin: parent.width * 0.1
            anchors.topMargin: parent.height * 0.1

            color: theme.tabBackgroundColor
            border.color: percToColor(vrData.tireGripFL)

            Rectangle {
                width: parent.width * (1 - vrData.tireGripFL)
                height: parent.height
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                color: percToColor(vrData.tireGripFL)
            }
        }

        Rectangle {
            id: frontRight
            anchors.right: parent.right
            anchors.top: parent.top
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.rightMargin: parent.width * 0.1
            anchors.topMargin: parent.height * 0.1

            color: theme.tabBackgroundColor
            border.color: percToColor(vrData.tireGripFR)

            Rectangle {
                width: parent.width * (1 - vrData.tireGripFR)
                height: parent.height
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: percToColor(vrData.tireGripFR)
            }
        }

        Rectangle {
            id: rearLeft
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.leftMargin: parent.width * 0.1
            anchors.bottomMargin: parent.height * 0.1

            color: theme.tabBackgroundColor
            border.color: percToColor(vrData.tireGripRL)

            Rectangle {
                width: parent.width * (1 - vrData.tireGripRL)
                height: parent.height
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                color: percToColor(vrData.tireGripRL)
            }
        }

        Rectangle {
            id: rearRight
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            width: parent.width * 0.35
            height: parent.height * 0.35
            anchors.rightMargin: parent.width * 0.1
            anchors.bottomMargin: parent.height * 0.1

            color: theme.tabBackgroundColor
            border.color: percToColor(vrData.tireGripRR)

            Rectangle {
                width: parent.width * (1 - vrData.tireGripRR)
                height: parent.height
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: percToColor(vrData.tireGripRR)
            }
        }
    }
}
