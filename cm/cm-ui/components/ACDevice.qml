import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12

Item {
    property alias clickArea: refreshButton.clickArea
    property alias deviceName: device.mainText
    property alias connected: connected.mainText
    property alias functional: functional.mainText

    width: 380
    height: 250
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


            GridLayout{
                anchors{
                    fill: parent
                    centerIn: parent
                    rightMargin: 50
                    topMargin: 30
                    margins: 20
                }

                rows: 3
                columns: 2

                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    ACRefreshButton{
                        id:refreshButton
                        anchors{
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                        }

                    }
                }

                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    ACTextAndDescription{
                        id:device
                        mainText: "Device X"
                        mainFontSize: Style.fontSizeAcMainText
                        descriptionText: "device name"
                        underlineWidth: Style.textAndDescriptionTextWidthBig
                        anchors{
                            centerIn: parent
                        }
                    }
                }

                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Text {
                        text: "Connected"
                        font.family: Style.fontTypeAcMain
                        font.pointSize: Style.fontSizeAcSubText
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: Style.colorAcLetter
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                    }
                }

                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    ACTextAndDescription{
                        id:connected
                        mainText: "Yes"
                        mainFontSize: Style.fontSizeAcSubText
                        descriptionText: "status"
                        anchors.centerIn: parent
                    }
                }

                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Text {
                        text: "Functional"
                        font.family: Style.fontTypeAcMain
                        font.pointSize: Style.fontSizeAcSubText
                        color: Style.colorAcLetter
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                    }
                }

                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    ACTextAndDescription{
                        id:functional
                        mainText: "Alright"
                        mainFontSize: Style.fontSizeAcSubText
                        descriptionText: "status"
                        anchors.centerIn: parent
                    }
                }
            }
        }
    }
}

