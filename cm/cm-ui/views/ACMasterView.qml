import QtQuick 2.15
import assets 1.0
import components 1.0
import CM 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls

Item {
    property Storage basicStorage: masterController.ui_basicStorage
    width: 1840
    height: 1080

    Item {
        anchors{
            fill: parent
            topMargin: 60
            leftMargin: 40
            rightMargin: 40
            bottomMargin: 20
        }
        Rectangle {
            id: background
            anchors.fill: parent
            color: Style.colorAcBackground
        }
        GridLayout {

            id: grid
            anchors{
                margins: 20
                fill: parent
            }
            columns: 2
            rows: 2
            anchors.centerIn: parent
            rowSpacing: 10
            columnSpacing: 20

            ACDummyComponent{
                Layout.preferredWidth: 900
                Layout.preferredHeight: 500
            }

            ACDummyComponent{
                Layout.preferredWidth: 700
                Layout.preferredHeight: 500

            }
            Item{
                width: 900
                height: 300


                ScrollView {
                    anchors.fill: parent
                    anchors.centerIn: parent
//                    contentWidth: row.width; contentHeight: row.height

                   ScrollBar.horizontal.interactive: true
                   ScrollBar.vertical.interactive: true
//                   ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
//                   ScrollBar.vertical.policy: ScrollBar.Alwaysoff
                   clip: true

//                    Keys.onUpPressed: scrollBar.decrease()
//                    Keys.onDownPressed: scrollBar.increase()

//                    ScrollBar.vertical: ScrollBar { id: scrollBar }

                    RowLayout{
                        id:row
                        anchors.fill: parent
                        spacing: 80
                        Item{
                            Layout.preferredWidth: 380
                            Layout.preferredHeight: 250
                            ACDevice{
                            }
                        }


                        Item{
                            Layout.preferredWidth: 380
                            Layout.preferredHeight: 250
                            ACDevice{
                            }
                        }

                        Item{
                            Layout.preferredWidth: 380
                            Layout.preferredHeight: 250
                            ACDevice{
                            }
                        }

                        Item{
                            Layout.preferredWidth: 380
                            Layout.preferredHeight: 250
                            ACDevice{
                            }
                        }
                    }
                }


            }

            ACDummyComponent{
                Layout.preferredWidth: 700
                Layout.preferredHeight: 250
            }
        }
    }
}
