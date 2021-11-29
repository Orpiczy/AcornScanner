import QtQuick 2.15
import CM 1.0
import assets 1.0
import QtQuick.Layouts 1.12

Item {
    implicitHeight: Style.cmCoffeMakeButtonHeight
    implicitWidth: Style.cmCoffeMakeButtonWidth

    RowLayout{
        anchors.fill: parent

    }

    Rectangle {
        id:edges
        anchors.fill: parent
        color: Style.colorCmChartEdges
        radius: width*0.05
    }
}
