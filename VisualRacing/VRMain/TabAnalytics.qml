import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle{
    color: theme.tabBackgroundColor

    TabView {
        id: tabView_Analytics
        width: parent.width - 10
        height: parent.height - 10
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        currentIndex: 0

        Tab {
            id: liveAnalyticsTab
            title: qsTr("Live") + vrMainWindow.emptyString
            SubTablLiveAnalytics{

            }
        }

        style: TabViewStyle {
            frameOverlap: 1
            tab: Rectangle {
                color: styleData.selected ? theme.appBackgroundColor : theme.tabInactiveColor
                implicitWidth: 80
                implicitHeight: 30

                Text {
                    id: text_label
                    anchors.centerIn: parent
                    text: styleData.title
                    color: theme.textColor
                }
            }
        }

    }
    /*Button {
        implicitWidth: 80
        implicitHeight: 30
        anchors.left: tabView_Analytics.left
        anchors.leftMargin: (tabView_Analytics.currentIndex + 1) * 80
        anchors.top: tabView_Analytics.top

        Rectangle {
            id: addButtonRect
            anchors.fill: parent
            color: theme.tabInactiveColor
            Text {
                id: addButtonText
                anchors.centerIn: parent
                text: qsTr("+") + vrMainWindow.emptyString
                color: theme.textColor
            }
        }

        onClicked: addNewTab()
        onHoveredChanged: addButtonRect.color = (hovered ? "#666666" : theme.tabInactiveColor) // COL

        function addNewTab(){
            console.log("here can stored data get loaded")
        }
    }*/
}
