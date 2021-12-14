import QtQuick 2.15
import assets 1.0
import components 1.0
import CM 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls
import QtCharts 2.3

Item {

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
                healthyValues: masterController.ui_dailyData.ui_healthy_list
                unhealthyValues: masterController.ui_dailyData.ui_unhealthy_list
                unknownValues: masterController.ui_dailyData.ui_unrecognized_list
                dates: masterController.ui_dailyData.ui_dates
                Layout.preferredWidth: 900
                Layout.preferredHeight: 500
            }

            ACMeasurementVisualization{
                Layout.preferredWidth: 700
                Layout.preferredHeight: 500

//                xAxisMin: 2000
//                xAxisMax: 2011
//                xTickCount: 3
//                yAxisMin: 0
//                yAxisMax: 5
//                yTickCount: 6

                result: masterController.ui_scannedData.ui_result
                fileName: masterController.ui_scannedData.ui_filename

                profileValue: LineSeries {
                    XYPoint { x: 2000; y: 0 }
                    XYPoint { x: 2001; y: 1 }
                    XYPoint { x: 2002; y: 1 }
                    XYPoint { x: 2011; y: 1 }
                }

                out1: masterController.ui_scannedData.ui_out1
                out2: masterController.ui_scannedData.ui_out2
                out3: masterController.ui_scannedData.ui_out3
                outA: masterController.ui_scannedData.ui_outA
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
                                deviceName: masterController.ui_profilometerDevice.ui_device_id
                                connected:  masterController.ui_profilometerDevice.ui_connection_status
                                functional: masterController.ui_profilometerDevice.ui_functional_status
                                ////connection add
                                clickArea.onClicked: {
                                    masterController.ui_profilometerDevice.updateStatus()
                                }
                            }
                        }

                        Item{
                            id:device2
                            Layout.preferredWidth: 380
                            Layout.preferredHeight: 250
                            ACDevice{
                                deviceName: masterController.ui_cameraDevice.ui_device_id
                                connected:  masterController.ui_cameraDevice.ui_connection_status
                                functional: masterController.ui_cameraDevice.ui_functional_status
                                ////connection add
                                clickArea.onClicked: {
                                    masterController.ui_cameraDevice.updateStatus()
                                }

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



            ACMeasureButton{
                Layout.preferredWidth: 700
                Layout.preferredHeight: 250
            }
        }
    }
}
