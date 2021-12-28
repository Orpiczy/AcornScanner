import QtQuick 2.15
import assets 1.0
import components 1.0
import QtQuick.Controls

Popup {

    property alias mainText: infoTextAndDescription.mainText
    property alias descriptionText: infoTextAndDescription.descriptionText

    id:mainPopup
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

    background:
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

        }
    }

    contentItem:
        Item {
        anchors.fill: parent
        ACTextAndDescription{
            id: infoTextAndDescription
            mainText: "Main Information"
            descriptionText: "Click Outside this popup to close it"
            anchors.centerIn: parent
        }
    }


    enter: Transition {
        NumberAnimation { property: "opacity"; from: 0.0; to: 1.0 }
    }

    exit: Transition {
        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
    }
}
