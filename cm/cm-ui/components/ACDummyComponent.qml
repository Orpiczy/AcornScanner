import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12

Item {
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

            ACTextAndDescription {
                anchors.centerIn: parent
            }
        }
    }
}
