import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12

Item {
    property MapDecorator mapDecorator

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


            ColumnLayout {
                spacing: 10
                anchors.fill: parent
                anchors.bottomMargin: 20
                Text {
                    id: title
                    text: "Water"
                    font.family: "Helvetica"
                    font.pointSize: 24
                    anchors.topMargin: 20
                    horizontalAlignment: Text.AlignHCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
                RadialBarShape{
                    id: waterType0
                    startAngle: 0
                    spanAngle: 360
                    minValue: 0
                    value: mapDecorator.ui_value0
                    maxValue: masterController.ui_basicStorage.ui_max_water
                    progressColor: Style.colorCmWaterCircleForeground
                    dialColor: Style.colorCmMilkCircleBackground
                    dialWidth: 30

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Text {
                        text: mapDecorator.ui_key0
                        anchors.centerIn: parent
                        font.family: "Helvetica"
                        font.pointSize: 24
                        horizontalAlignment: Text.AlignHCenter
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }
            }
        }
    }
}



