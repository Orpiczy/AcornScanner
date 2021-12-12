import QtQuick 2.15
import assets 1.0
import components 1.0
import CM 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls
import QtCharts 2.3



Item {
//    property alias xAxisMin: mainChart.xAxisMin
//    property alias xAxisMax: mainChart.xAxisMax
//    property alias xTickCount: mainChart.xTickCount
//    property alias yAxisMin: mainChart.yAxisMin
//    property alias yAxisMax: mainChart.yAxisMax
//    property alias yTickCount: mainChart.yTickCount

    property alias result: result.mainText
    property alias fileName: fileName.mainText

    property alias profileValue:  mainChart.profileValue
    property alias out1: out1.mainText
    property alias out2: out2.mainText
    property alias out3: out3.mainText
    property alias outA: outA.mainText

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

            ColumnLayout{
                anchors{
                    topMargin: 15
                    bottomMargin: 20
                    fill: parent
                }
                Item{
                    implicitHeight: title.height
                    implicitWidth: parent.width
                    Text {
                        id: title
                        text: "Last Measurement Data"
                        font.family: Style.fontTypeAcMain
                        font.pointSize: Style.fontSizeAcMainText
                        color: Style.colorAcLetter
                        horizontalAlignment: Text.AlignHCenter
                        anchors{
                            horizontalCenter: parent.horizontalCenter

                        }
                    }
                }
                Item{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    GridLayout{
                        anchors{
                            fill: parent
                            margins: 10
                        }
                        rows: 5
                        columns: 2

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true

                            ACTextAndDescription{
                                id:result
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "analyze result"
                                underlineWidth: Style.textAndDescriptionTextWidthBig
                                anchors{
                                    centerIn: parent
                                }
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true

                            ACTextAndDescription{
                                id:fileName
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "measurement save file name"
                                underlineWidth: Style.textAndDescriptionTextWidthBig
                                anchors{
                                    centerIn: parent
                                }
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.rowSpan: 4
                            ACProfileChart{
                                id:mainChart
                                anchors.right: parent.right
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:out1
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "out1"
                                anchors.centerIn: parent
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:out2
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "out2"
                                anchors.centerIn: parent
                            }
                        }


                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:out3
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "out3"
                                anchors.centerIn: parent
                            }
                        }


                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:outA
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "outA"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }
    }
}

