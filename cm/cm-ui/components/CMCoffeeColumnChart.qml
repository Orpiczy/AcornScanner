import QtQuick 2.15
import CM 1.0
import assets 1.0
import QtCharts 2.3

Item {
    property MapDecorator mapDecorator


    implicitHeight: Style.cmChartHeight
    implicitWidth: Style.cmChartWidth
    Rectangle {
        id:edges
        anchors.fill: parent
        color: Style.colorCmChartEdges
        radius: Style.cmChartWidth*0.05
        ChartView {
            anchors.fill: parent
            theme: ChartView.ChartThemeBrownSand
            title: "<b>Coffee</b>"
            antialiasing: true
            backgroundRoundness: Style.cmChartWidth*0.05
            anchors.margins: -5
            legend.alignment: Qt.AlignBottom
            plotAreaColor: Style.colorCmChartBox
            backgroundColor: Style.colorCmChartBox
            BarSeries {
                id: mySeries
                axisX: BarCategoryAxis { categories: [mapDecorator.ui_key0, mapDecorator.ui_key1, mapDecorator.ui_key3, mapDecorator.ui_key4, mapDecorator.ui_key5, mapDecorator.ui_key6 ] }
                BarSet { label: "Coffee Left"; values: [mapDecorator.ui_value0, mapDecorator.ui_value1, mapDecorator.ui_value2, mapDecorator.ui_value3, mapDecorator.ui_value4, mapDecorator.ui_value5,mapDecorator.ui_value6] }
            }
        }
    }}
