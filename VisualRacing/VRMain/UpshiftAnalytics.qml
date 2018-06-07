import QtQuick 2.0

Rectangle {
    color: theme.appBackgroundColor

    Text {
        id: upShiftTitle
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: 15
        anchors.rightMargin: 15
        width: parent.width - 30
        horizontalAlignment: Text.AlignRight

        color: theme.tabBackgroundColor
        text: qsTr("Upshift") + vrMainWindow.emptyString

        font {
            pointSize: 50
            bold: true
        }
        minimumPointSize: 2
        fontSizeMode: Text.Fit
    }

    Rectangle {
        id: lastUpShiftContainer
        width: parent.width
        height: parent.height * 0.33
        anchors.left: parent.left
        anchors.top: parent.top

        color: "transparent"

        Text {
            color: theme.textColor
            text: qsTr("Last Upshift") + vrMainWindow.emptyString

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
            color: theme.textColor
            text: "" + vrMetrics.clutchDisengagedTime

            height: parent.height * 0.7
            width: parent.width * 0.5
            anchors.bottom: cdtLabel.top
            anchors.left: parent.left

            font {
                pointSize: 70
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: cdtLabel
            color: theme.textColor
            text: qsTr("Clutch disengaged (in ms)") + vrMainWindow.emptyString

            anchors.margins: 5
            height: parent.height * 0.1
            width: parent.width * 0.5
            anchors.left: parent.left
            anchors.bottom: parent.bottom

            font {
                pointSize: 50
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            color: theme.textColor
            text: "" + vrMetrics.gearChangeTime

            height: parent.height * 0.7
            width: parent.width * 0.5
            anchors.bottom: gctLabel.top
            anchors.right: parent.right

            font {
                pointSize: 70
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: gctLabel
            color: theme.textColor
            text: qsTr("Gear change (in ms)") + vrMainWindow.emptyString

            anchors.margins: 5
            height: parent.height * 0.1
            width: parent.width * 0.5
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            font {
                pointSize: 50
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
        }
    }

    Rectangle {
        id: diffContainer
        width: parent.width
        anchors.left: parent.left
        anchors.top: lastUpShiftContainer.bottom
        anchors.bottom: avgUpShiftContainer.top

        color: "transparent"

        Rectangle {
            id: colorIndicator
            width: parent.width * 0.75
            height: parent.height * 0.8
            anchors.centerIn: parent
            radius: 12

            color: "transparent"

            Text {
                text: vrMetrics.diffToAvgShiftTime >= 0 ? "+" + vrMetrics.diffToAvgShiftTime: "" + vrMetrics.diffToAvgShiftTime
                color: theme.textColor

                anchors.fill: parent

                font {
                    pointSize: 70
                    bold: true
                }
                minimumPointSize: 2
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Connections {
            target: vrMetrics
            onDiffToAvgShiftTimeChanged: diffContainer.updateColor()
            onMinClutchDisTimeChanged: diffContainer.setColorToBest()
        }

        function setColorToBest() {
            colorIndicator.color = "mediumorchid";
        }

        function updateColor() {
            if (vrMetrics.diffToAvgShiftTime === 0)
                colorIndicator.color = "gold";
            else if (vrMetrics.diffToAvgShiftTime > 0)
                colorIndicator.color = "red";
            else
                colorIndicator.color = "lime";
        }
    }

    Rectangle {
        id: avgUpShiftContainer
        width: parent.width
        height: parent.height * 0.33
        anchors.left: parent.left
        anchors.bottom: upShiftTitle.top

        color: "transparent"

        Text {
            color: theme.textColor
            text: qsTr("Average") + vrMainWindow.emptyString

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
            color: theme.textColor
            text: "" + vrMetrics.avgClutchDisTime

            height: parent.height * 0.7
            width: parent.width * 0.5
            anchors.bottom: avgCdtLabel.top
            anchors.left: parent.left

            font {
                pointSize: 70
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: avgCdtLabel
            color: theme.textColor
            text: qsTr("Clutch disengaged (in ms)") + vrMainWindow.emptyString

            anchors.margins: 5
            height: parent.height * 0.1
            width: parent.width * 0.5
            anchors.left: parent.left
            anchors.bottom: parent.bottom

            font {
                pointSize: 50
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            color: theme.textColor
            text: "" + vrMetrics.avgGearChangTime

            height: parent.height * 0.7
            width: parent.width * 0.5
            anchors.bottom: avgGctLabel.top
            anchors.right: parent.right

            font {
                pointSize: 70
                bold: true
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: avgGctLabel
            color: theme.textColor
            text: qsTr("Gear change (in ms)") + vrMainWindow.emptyString

            anchors.margins: 5
            height: parent.height * 0.1
            width: parent.width * 0.5
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            font {
                pointSize: 50
            }
            minimumPointSize: 2
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
        }
    }
}
