import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12

Item {
    implicitHeight: Style.cmChartHeight
    implicitWidth: Style.cmChartWidth
    Rectangle {
        id:edges
        anchors.fill: parent
        color: Style.colorCmChartEdges
        radius: Style.cmChartWidth*0.05
        Rectangle {
            id:box
            anchors{
                margins: 5
                fill: parent
            }
            color: Style.colorCmChartBox
            radius: Style.cmChartWidth*0.05
            Text {
                id: title
                text: "Control Panel"
                font.family: "Helvetica"
                font.pointSize: 40
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
