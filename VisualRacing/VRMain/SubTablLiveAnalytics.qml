import QtQuick 2.0
import VRMetrics 1.0

Rectangle{
    color: theme.appBackgroundColor

    AccelerationAnalytics {
        id: accelBehav
        anchors.left: parent.left
        anchors.top: parent.top
        height: parent.height
        width: parent.width * .35
    }

    CarInfoForAnalytics {
        id: general
        anchors.centerIn: parent
        height: parent.height
        width: parent.width * .3
    }

    UpshiftAnalytics {
        id: upShift
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height
        width: parent.width * .35
    }
}
