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

            ACStatisticDataChart{
                healthyValues: [2, 2, 3, 4, 5, 6]
                unhealthyValues: [5, 1, 2, 4, 1, 7]
                unknownValues: [3, 5, 8, 13, 5, 8]
                dates: ["29-11-2021", "28-11-2021", "27-11-2021", "26-11-2021", "25-11-2021", "24-11-2021" ]
                Layout.preferredWidth: 900
                Layout.preferredHeight: 500
            }

            ACDummyComponent{
                Layout.preferredWidth: 700
                Layout.preferredHeight: 500
                ACProfileChart{
                    anchors.centerIn: parent
                }


            }
            Item{
                width: 900
                height: 300


                ScrollView {

                    anchors{
                        leftMargin: 20
                        rightMargin: 20
                        centerIn: parent
                    }
                    //                    contentWidth: row.width; contentHeight: row.height

                    ScrollBar.horizontal.interactive: true
                    ScrollBar.vertical.interactive: true
                    ScrollBar.horizontal.policy: parent.width <= row.width ? ScrollBar.AlwaysOn : ScrollBar.AlwaysOff
                    clip: true

                    //                    Keys.onUpPressed: scrollBar.decrease()
                    //                    Keys.onDownPressed: scrollBar.increase()

                    //                    ScrollBar.vertical: ScrollBar { id: scrollBar }

                    RowLayout{
                        id:row
                        anchors.fill: parent
                        anchors.centerIn: parent
                        spacing: 80

                        Item{
                            id:device1
                            Layout.preferredWidth: 380
                            Layout.preferredHeight: 250
                            ACDevice{
                            }
                        }

                        Item{
                            id:device2
                            Layout.preferredWidth: 380
                            Layout.preferredHeight: 250
                            ACDevice{
                            }
                        }

//                        Item{
//                            id:device3
//                            Layout.preferredWidth: 380
//                            Layout.preferredHeight: 250
//                            ACDevice{
//                            }
//                        }

//                        Item{
//                            id:device4
//                            Layout.preferredWidth: 380
//                            Layout.preferredHeight: 250
//                            ACDevice{
//                            }
//                        }
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
