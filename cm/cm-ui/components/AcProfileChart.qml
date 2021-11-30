import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12
import QtCharts 2.3
import Qt5Compat.GraphicalEffects

Item {
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
                    axisX: ValuesAxis { min: 2000; max: 2011;tickCount: 3;labelFormat: "%.0f"; color: Style.colorAcProfileChartBackground; labelsVisible: false; gridVisible:false}
                    axisY: ValuesAxis {min: 0; max:5;tickCount: 6;labelFormat: "%d"; color: Style.colorAcProfileChartBackground;labelsVisible: false; gridVisible:false}
                    borderColor: Style.colorAcEdges
                    color:Style.colorAcAccent1
                    borderWidth: 1

                    upperSeries: LineSeries {
                        XYPoint { x: 2000; y: 0 }
                        XYPoint { x: 2001; y: 1 }
                        XYPoint { x: 2002; y: 2 }
                        XYPoint { x: 2003; y: 3 }
                        XYPoint { x: 2004; y: 4 }
                        XYPoint { x: 2005; y: 4 }
                        XYPoint { x: 2006; y: 3 }
                        XYPoint { x: 2007; y: 4 }
                        XYPoint { x: 2008; y: 4 }
                        XYPoint { x: 2009; y: 3 }
                        XYPoint { x: 2010; y: 2 }
                        XYPoint { x: 2011; y: 1 }
                    }


                }
                Component.onCompleted: {
                   profileChart.legend.visible = false
            //       helper.update_chart(profileChart)
                }
            }

        }
    }
}
