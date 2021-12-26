import QtQuick 2.0
import assets 1.0


Item {
    property alias clickArea: clickArea
    property alias boxColor: box.color
    property alias text: textArea.text
    property real radiusProportionality: 1.2
    property color boxClickedColor: Style.colorAcNavigationButtonBackgroundHovered
    signal buttonClicked()

    height: 1.1*Style.acButtonDimension
    width: 2.5*Style.acButtonDimension

    Rectangle {
        id:edges

        anchors.fill: parent
        color: Style.colorAcEdges
        radius: radiusProportionality*Style.acButtonEdgesRadius

        Rectangle {
            id:box
            anchors{
                margins: 2
                fill: parent
            }
            color: Style.colorAcNavigationButtonBackground
            radius: radiusProportionality*Style.acButtonEdgesRadius
            Text {
                id:textArea
                font {
                    family: Style.fontTypeAcMain
                    pixelSize: parent.height * 0.6
                }
                text: "LongButton"
                color: Style.colorAcLetter
                anchors.centerIn: parent
            }

            MouseArea {
                id:clickArea
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true
                onEntered: box.state = "hover"
                onExited: box.state = ""
                onClicked: {
                    buttonClicked();
                }
            }

            states: [
                State {
                    name: "hover"
                    PropertyChanges {
                        target: box
                        color:  boxClickedColor
                    }
                }
            ]
        }
    }
}
