import QtQuick 2.15
import assets 1.0
import components 1.0
import CM 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls
import QtCharts 2.3



Item {
    property alias result: result.mainText
    property alias fileName: fileName.mainText

    property alias profileValue:  mainChart.profileValue
    property alias statusOflongitudinalCrossSection: statusOflongitudinalCrossSection.mainText
    property alias statusOfTransverseCrossSection: statusOfTransverseCrossSection.mainText
    property alias statusOfBasicPhoto: statusOfBasicPhoto.mainText
    property alias statusOfCrossSectionPhoto: statusOfCrossSectionPhoto.mainText

    //areas
    property alias clickAreaLongitudinalCrossSectionBtn: longitudinalCrossSectionBtn.clickArea
    property alias clickAreaTransverseCrossSectionBtn: transverseCrossSectionProfileBtn.clickArea
    property alias clickAreaBasicPhotoBtn: basicPhotoBtn.clickArea
    property alias clickAreaCrossSectionPhotoBtn: crossSectionPhotoBtn.clickArea

    property alias clickAreaAnalyzeBtn: analyzeBtn.clickArea
    property alias clickAreaCameraViewBtn: cameraViewBtn.clickArea
    property alias clickAreaSaveBtn: saveBtn.clickArea


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
                        text: "Measurement Data"
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
                        rows: 6
                        columns: 3

                        Item{
                            Layout.preferredWidth: 1.2*mainChart.width
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
                            Layout.columnSpan: 2
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
                            Layout.fillHeight: true
                            Layout.preferredWidth: 1.2*mainChart.width
                            Layout.rowSpan: 5
                            ACProfileChart{
                                id:mainChart
                                anchors.centerIn: parent
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:statusOflongitudinalCrossSection
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "Longitudinal Cross Section"
                                anchors{
                                    verticalCenter: parent.verticalCenter
                                    right: parent.right
                                }
                            }
                        }
                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACBasicButton{
                                id: longitudinalCrossSectionBtn//profil wzdłużny
                                icon: "\uf002"
                                anchors.centerIn: parent
                            }

                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:statusOfTransverseCrossSection
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "Transverse Cross Section"
                                anchors{
                                    verticalCenter: parent.verticalCenter
                                    right: parent.right
                                }
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACBasicButton{
                                id: transverseCrossSectionProfileBtn //profil poprzeczny
                                icon: "\uf002"
                                anchors.centerIn: parent
                            }

                        }


                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:statusOfBasicPhoto
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "Basic Photo"
                                anchors{
                                    verticalCenter: parent.verticalCenter
                                    right: parent.right
                                }
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACBasicButton{
                                id: basicPhotoBtn
                                icon: "\uf030"
                                anchors.centerIn: parent
                            }

                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACTextAndDescription{
                                id:statusOfCrossSectionPhoto
                                mainFontSize: Style.fontSizeAcMainTextDataVis
                                descriptionText: "Cross Section Photo"
                                anchors{
                                    verticalCenter: parent.verticalCenter
                                    right: parent.right
                                }
                            }
                        }

                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACBasicButton{
                                id: crossSectionPhotoBtn
                                icon: "\uf030"
                                anchors.centerIn: parent
                            }

                        }
                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            RowLayout{
                                anchors.fill: parent
                                spacing: 10
                                ACBasicButton{
                                    id: cameraViewBtn
                                    icon: "\uf030"
                                }

                                ACBasicButtonLong{
                                    id: analyzeBtn
                                    text: "Analyze"
                                    boxColor: Style.colorAcMeasureButton
                                    boxClickedColor: Style.colorAcMeasureButtonClicked
                                }
                            }



                        }
                        Item{
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ACBasicButtonLong{
                                id: saveBtn
                                text: "Save"
                                anchors.centerIn: parent
                            }

                        }
                    }
                }
            }
        }
    }
}
