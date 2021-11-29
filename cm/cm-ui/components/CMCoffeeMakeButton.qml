import QtQuick 2.15
import CM 1.0
import assets 1.0

Item {
    implicitHeight: Style.cmCoffeMakeButtonHeight
    implicitWidth: Style.cmCoffeMakeButtonWidth
    Rectangle {
        id:edges
        anchors.fill: parent
        color: Style.colorCmChartEdges
        radius: width*0.05
        Rectangle {
            id: mainChartBox
            color: Style.colorCmChartBox
            anchors {
                fill: parent
                margins: 2
            }
            radius: width*0.05
            Text {
                id: textLabel
                anchors {
                    fill: parent
                    centerIn: parent
                }
//                text: stringDecorator.ui_label
                text: "CoffeeMakeButton"
                color: Style.colourDataControlsFont
                font.pixelSize: Style.pixelSizeDataControls
                verticalAlignment: Qt.AlignVCenter
                horizontalAlignment: Qt.AlignHCenter
            }
        }
    }
}


