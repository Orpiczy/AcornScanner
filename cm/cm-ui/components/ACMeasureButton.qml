import QtQuick 2.15
import CM 1.0
import assets 1.0
import components 1.0
import QtQuick.Layouts 1.12

Item {
    property alias status: status.mainText
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
                    leftMargin: 20
                }

                rows: 3
                columns: 2

                Item{
                    Layout.preferredWidth: parent.width - measureButton.width
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
                    id: measureButton
                    Layout.preferredWidth: parent.width * 0.6
                    Layout.fillHeight: true
                    Layout.rowSpan: 3
                    Rectangle {
                        id:measureButtonEdges
                        anchors{
                            fill: parent
                            centerIn: parent
                            margins: 10
                            rightMargin: 16
                        }

                        color: Style.colorAcEdges
                        radius: Style.acEdgesRadius
                        Rectangle {
                            id:measureButtonBox
                            anchors{
                                margins: 2
                                fill: parent
                            }
                            color: Style.colorAcMeasureButton
                            radius: Style.acEdgesRadius

                            Text {
                                id:measureButtonText
                                text: "Measure"
                                font.family: Style.fontTypeAcMain
                                font.pointSize: Style.fontSizeAcSubTitle
                                color: Style.colorAcLetter
                                anchors.centerIn: parent
                            }
                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                hoverEnabled: true
                                onEntered: measureButtonBox.state = "hover";
                                onExited:  measureButtonBox.state = "";
                                onClicked:{
                                        measureButtonBox.state = "clickedAndWorking";
                                        masterController.onMeasureButtonClicked();
                                        measureButtonBox.state = ""
                                }
                            }
                            states: [
                                State {
                                    name: "hover"
                                    PropertyChanges {
                                        target: measureButtonBox
                                        color:  Style.colorAcMeasureButtonClicked
                                    }
                                    PropertyChanges {
                                        target: measureButtonText
                                        text: "Click to Start"
                                    }
                                },
                                State {
                                    name: "clickedAndWorking"
                                    PropertyChanges {
                                        target: measureButtonBox
                                        color: Style.colorAcMeasureButtonClickedAndWorking
                                    }
                                    PropertyChanges {
                                        target: measureButtonText
                                        text: "Measuring ..."
                                    }
                                }
                            ]

                        }
                    }

                }

                Item{
                    Layout.preferredWidth: parent.width - measureButton.width
                    Layout.fillHeight: true
                    Layout.rowSpan: 2
                    ACTextAndDescription{
                        id:status
                        mainText: "Ready"
                        mainFontSize: Style.fontSizeAcMainText
                        descriptionText: "status"
                        anchors{
                            horizontalCenter: parent.horizontalCenter
                            top: parent.top
                            topMargin: -10
                        }

                    }
                }


            }
        }
    }


}


