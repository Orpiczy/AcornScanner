import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12
import QtCharts 2.3
import Qt5Compat.GraphicalEffects

Item {
    property alias xAxisMin: xAxis.min
    property alias xAxisMax: xAxis.max
    property alias xTickCount: xAxis.tickCount

    property alias yAxisMin: yAxis.min
    property alias yAxisMax: yAxis.max
    property alias yTickCount: yAxis.tickCount

    property alias profileValue: profile.upperSeries
    width: 300
    height: 300
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
            color: Style.colorAcProfileChartBackground
            radius: Style.acEdgesRadius

            ChartView {
                id: profileChart
                anchors.fill: parent
                antialiasing: true
                backgroundColor: Style.colorAcProfileChartBackground
                // Define x-axis to be used with the series instead of default one
                backgroundRoundness: Style.acEdgesRadius
//                LinearGradient {
//                    id: gradient
//                    anchors.fill: parent
//                    start: Qt.point(0, 0)
//                    end: Qt.point(0,100)
//                    gradient: Gradient {
//                        GradientStop { position: 0.0; color: Style.colorAcAccent1 }
//                        GradientStop { position: 1.0; color: Style.colorAcProfileChartBackground }
//                    }
//                }
                AreaSeries {

                    id:profile
                    axisX: ValuesAxis { id: xAxis; labelFormat: "%d"; color: Style.colorAcProfileChartBackground; labelsVisible: false; gridVisible:false}
                    axisY: ValuesAxis { id: yAxis; labelFormat: "%d"; color: Style.colorAcProfileChartBackground; labelsVisible: false; gridVisible:false}
                    borderColor: Style.colorAcEdges
                    color:Style.colorAcProfileChartMain
                    borderWidth: 2

                }
                Component.onCompleted: {
             //      profileChart.legend.visible = false
                  masterController.ui_scannedData.ui_profile = profile.upperSeries
                }
            }

        }
    }
}
