import QtQuick 2.15
import assets 1.0
import components 1.0
import CM 1.0
import QtQuick.Layouts 1.12

Item {
    property Storage basicStorage: masterController.ui_basicStorage
    width: 1840
    height: 1080
    Image {
        id: backgroundPhoto
        height:1080
        width: 1920
        source: "qrc:/assets/ControlViewBackground.png"
        anchors.centerIn: parent
    }
    Item {
        anchors{
            fill: parent
            topMargin: 60
            leftMargin: 40
            rightMargin: 40
            bottomMargin: 20
        }

        GridLayout {

            id: grid
            columns: 3
            rows: 2
            anchors{
                margins: 20
                fill: parent
            }
            anchors.centerIn: parent
            rowSpacing: 20
            columnSpacing: 20

            CMChangeColumnChart{
                mapDecorator: basicStorage.ui_change
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            CMMilkCircularChart{
                mapDecorator: basicStorage.ui_milk
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            CMWaterCircularChart{
                mapDecorator: basicStorage.ui_water
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            ColumnLayout{
                spacing: 20

                CMCoffeeColumnChart{
                    mapDecorator: basicStorage.ui_coffee
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
                CMCoffeeMakeButton{
                    Layout.alignment:  Qt.AlignRight
                }
            }



            CMControlPanel{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Item {
                implicitHeight: Style.cmChartHeight
                implicitWidth: Style.cmChartWidth
                Layout.fillWidth: true
                Layout.fillHeight: true

                Image {
                    id: coffeIcon
                    source: "qrc:/assets/coffeeMaker.svg"
                    anchors.centerIn: parent
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
