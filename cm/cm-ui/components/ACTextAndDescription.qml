import QtQuick 2.15
import CM 1.0
import assets 1.0
import QtQuick.Layouts 1.12

Item {
    id: deviceParent

    property alias mainText: mainText.text
    property alias mainFontSize: mainText.font.pointSize
    property alias descriptionText: description.text
    property alias descriptionFontSize:description.font.pointSize
    property alias underlineThickness: underline.height
    property alias underlineWidth: deviceParent.width


    height: Style.textAndDescriptionTextHeight
    width: 100 //Style.textAndDescriptionTextWidth nie dziala z tym

    Column{
        anchors.fill: parent

        Text {
            id: mainText
            text: "DEVICE NAME"
            font.family: Style.fontTypeAcMain
            font.pointSize: Style.fontSizeAcMainText
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Rectangle{
            id:underline
            width: parent.width
            height: 2
            color: Style.colorAcTextUnderline
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            id: description
            text: "description"
            font.family: Style.fontTypeAcMain
            font.pointSize: Style.fontSizeAcDescription
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
