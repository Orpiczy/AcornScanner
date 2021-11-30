import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12
import QtCharts 2.3

Item {
    property alias healthyValues: healthy.values
    property alias unhealthyValues: unhealthy.values
    property alias unknownValues: unknown.values
    property alias dates: category.categories

    Rectangle {
        id:edges
        anchors.fill: parent
        color: Style.colorAcEdges
        radius: Style.acEdgesRadius
        Rectangle {
            id:box
            anchors{
                margins: 2
                fill: parent
            }
            color: Style.colorAcBackground
            radius: Style.acEdgesRadius
            ColumnLayout{
                anchors{
                    topMargin: 15
                    fill: parent
                }
                Item{
                    implicitHeight: title.height
                    implicitWidth: parent.width
                    Text {
                        id: title
                        text: "Measurement Statistics"
                        font.family: Style.fontTypeAcMain
                        font.pointSize: Style.fontSizeAcMainText
                        horizontalAlignment: Text.AlignHCenter
                        anchors{
                            horizontalCenter: parent.horizontalCenter

                        }
                    }
                }
                Item{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    ChartView {
                        //  title: "Bar series"
                        id: statisticChart

                        anchors{
                            fill: parent
                            bottomMargin: 15
                            rightMargin: 2
                            leftMargin: 2
                        }


                        legend.alignment: Qt.AlignBottom

                        legend.font.pixelSize: 15
//                        legend.font: Style.fontTypeAcMain
                        antialiasing: true

                        BarSeries {
                            id: mySeries
                            axisY: ValuesAxis {max: 15; min: 0; tickCount: 6; labelFormat: "%d"; }
                            axisX: BarCategoryAxis { id:category }
                            //pen: healthy.pen.setCapStyle(Qt.RoundCap)

                            BarSet { id:healthy; label: "Healthy"; labelFont.pixelSize: 15; color: Style.colorAcAccent1; borderColor: Style.colorAcEdges; borderWidth: 1; }
                            BarSet { id:unhealthy; label: "Unhealthy";  labelFont.pixelSize: 15 ; color: Style.colorAcAccent2; borderColor: Style.colorAcEdges; borderWidth: 1 }
                            BarSet { id:unknown; label: "Unknown"; labelFont.pixelSize: 15; color: Style.colorAcAccent3; borderColor: Style.colorAcEdges; borderWidth: 1 }
                        }
                    }
                }
            }
        }
    }
}
