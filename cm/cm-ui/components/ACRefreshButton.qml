import QtQuick 2.0
import assets 1.0


Item {

    property int deviceId
    signal refreshButtonClicked(int deviceId)

    height: Style.acButtonDimension
    width: Style.acButtonDimension

    Rectangle {
        id:edges

        anchors.fill: parent
        color: Style.colorAcEdges
        radius: Style.acButtonEdgesRadius

        Rectangle {
            id:box
            anchors{
                margins: 2
                fill: parent
            }
            color: Style.colorAcNavigationButtonBackground
            radius: Style.acButtonEdgesRadius

            Text {
                id: textIcon
                font {
                    family: Style.fontAwesome
                    pixelSize: (parent.height - 10)
                }
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: Style.colorAcEdges
                anchors{
                    fill: parent
                }
                //                text: "\uf2f1"
                text: "\uf01e"
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true
                onEntered: box.state = "hover"
                onExited: box.state = ""
                onClicked: refreshButtonClicked(deviceId)
            }

            states: [
                State {
                    name: "hover"
                    PropertyChanges {
                        target: box
                        color: Style.colorAcNavigationButtonBackgroundHovered
                    }
                }
            ]
        }
    }
}



/*##^##
Designer {
    D{i:0;formeditorZoom:16}
}
##^##*/
