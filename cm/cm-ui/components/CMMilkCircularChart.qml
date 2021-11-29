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
            Text {
                id: title
                text: "Milk"
                font.family: "Helvetica"
                font.pointSize: 24
                anchors{
                    top: parent.top
                    left: parent.left
                    right: parent.right
                    topMargin: 10
                    bottom: layout.top
                }
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            RowLayout{
                id: layout
                anchors{
                    fill: parent
                    top: title.bottom
                    topMargin: 30
                    margins: 20
                }

                spacing: 20
                ColumnLayout {
                    spacing: 6
                    Layout.fillWidth: true
                    Layout.fillHeight: true


                    RadialBarShape{
                        id: milkType0
                        startAngle: 0
                        spanAngle: 360
                        minValue: 0
                        value: mapDecorator.ui_value0
                        maxValue: masterController.ui_basicStorage.ui_max_milk
                        progressColor: Style.colorCmMilkCircleForeground
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
                ColumnLayout {
                    spacing: 6
                    Layout.fillWidth: true
                    Layout.fillHeight: true


                    RadialBarShape{
                        id: milkType1
                        startAngle: 0
                        spanAngle: 360
                        minValue: 0
                        value: mapDecorator.ui_value1
                        maxValue: masterController.ui_basicStorage.ui_max_milk
                        progressColor: Style.colorCmMilkCircleForeground
                        dialColor: Style.colorCmMilkCircleBackground
                        dialWidth: 30
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Text {
                            text: mapDecorator.ui_key1
                            font.family: "Helvetica"
                            font.pointSize: 24
                            anchors.centerIn: parent
                            horizontalAlignment: Text.AlignHCenter
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                        }
                    }
                }
            }
        }
    }
}

