import QtQuick 2.0

Rectangle {
    color: theme.appBackgroundColor

    Rectangle {
        id: pedalInfo

        anchors.top: parent.top
        height: parent.height * 0.5
        width: parent.width

        color: theme.tabBackgroundColor

        Rectangle {
            id: clutch

            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.1
            anchors.verticalCenter: brake.verticalCenter
            height: parent.height * 0.8
            width: parent.width * 0.2

            color: theme.appBackgroundColor

            Rectangle {
                anchors.bottom: parent.bottom
                width: parent.width
                height: parent.height * vrData.clutch

                color: "#394ead"
            }
        }

        Rectangle {
            id: brake

            anchors.centerIn: parent
            height: parent.height * 0.8
            width: parent.width * 0.2

            color: theme.appBackgroundColor

            Rectangle {
                anchors.bottom: parent.bottom
                width: parent.width
                height: parent.height * vrData.brake

                color: "#ad3954"
            }
        }

        Rectangle {
            id: throttle

            anchors.right: parent.right
            anchors.rightMargin: parent.width * 0.1
            anchors.verticalCenter: brake.verticalCenter
            height: parent.height * 0.8
            width: parent.width * 0.2

            color: theme.appBackgroundColor

            Rectangle {
                anchors.bottom: parent.bottom
                width: parent.width
                height: parent.height * vrData.throttle

                color: "#3dad39"
            }
        }
    }

    Rectangle {
        id: drivetrainInfo

        anchors.bottom: parent.bottom
        height: parent.height * 0.5
        width: parent.width

        color: theme.tabBackgroundColor

        Rectangle { // TODO: Copy and pasted from general tab
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

        Text { // TODO: Copy and pasted from general tab
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
    }
}
