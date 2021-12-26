pragma Singleton
import QtQuick 2.15

Item {


    readonly property color colourBackground: "#efefef"

    //icons
    property alias fontAwesome: fontAwesomeLoader.name
    FontLoader {
        id: fontAwesomeLoader
        source: "qrc:/assets/fontawesome.ttf"
    }

    //toolbar params
    readonly property real widthNavigationBarCollapsed: widthNavigationButtonIcon
    readonly property real heightNavigationBarExpanded: widthNavigationButton

    //navigation bar basic params
    readonly property color colourNavigationBarFont: "#4B2827"
    readonly property color colourNavigationBarBackground: "#F5EBE4"

    //icon and text size
    readonly property int pixelSizeNavigationBarText: 22
    readonly property int pixelSizeNavigationBarIcon: 42

    //navigation bar size params
    readonly property real widthNavigationButtonIcon: 80
    readonly property real widthNavigationButtonDescription: 160
    readonly property real widthNavigationButton: widthNavigationButtonIcon + widthNavigationButtonDescription

    readonly property real heightNavigationButtonIcon: widthNavigationButtonIcon
    readonly property real heightNavigationButtonDescription: heightNavigationButtonIcon
    readonly property real heightNavigationButton: Math.max(heightNavigationButtonIcon,heightNavigationButtonDescription)

    //cmd bar components
    readonly property color colourCommandBarBackground: "#cecece"
    readonly property color colourCommandBarFont: "#131313"
    readonly property color colourCommandBarFontDisabled: "#636363"
    readonly property real heightCommandBar: heightCommandButton
    readonly property int pixelSizeCommandBarIcon: 32
    readonly property int pixelSizeCommandBarText: 12
    readonly property real widthCommandButton: 80
    readonly property real heightCommandButton: widthCommandButton

    //textComponent
    readonly property real sizeScreenMargin: 20
    readonly property color colourDataControlsBackground: "#ffffff"
    readonly property color colourDataControlsFont: "#131313"
    readonly property int pixelSizeDataControls: 18
    readonly property real widthDataControls: 400
    readonly property real heightDataControls: 40

    //AC colors
    readonly property color colorAcBackground: "#FFFFFF"
    readonly property color colorAcForeground: "#E4E4E4"
    readonly property color colorAcEdges: "#707070"
    readonly property color colorAcLetter: "#707070"
    readonly property color colorAcAccent1: "#309975"
    readonly property color colorAcAccent2: "#454D66"
    readonly property color colorAcAccent3: "#E4E4E4"
    readonly property color colorAcMeasureButton1: "#F2ED60"
    readonly property color colorAcMeasureButton2: "#60F273"
    readonly property color colorAcNavigationBarBackground: "#E4E4E4"
    readonly property color colorAcNavigationButtonBackground: "#E4E4E4"
    readonly property color colorAcTextUnderline: "#E4E4E4"
    readonly property color colorAcNavigationButtonBackgroundHovered: "#D6D6D6"
    readonly property color colorAcProfileChartBackground: "#E4E4E4"
    readonly property color colorAcProfileChartMain: "#309975"
    readonly property color colorAcMeasureButton: "#DAD873"
    readonly property color colorAcMeasureButtonClicked:"#F2F060"
    readonly property color colorAcMeasureButtonClickedAndWorking: "#D6D6D6"
    readonly property color colorAcVisualizationAnalyzeButton: "#DAD873"
    readonly property color colorAcVisualizationSaveButton: "#309975"

    function getColorAlpha(colorHex, alpha = 0.4) {
        // TO DO - figure out this
        //return Qt.hsla(color.hslHue, color.hslSaturation, color.hslLightness, alpha)
        //return Qt.rgba(1, 0, 0, 0.4);
    }

    //dim
    readonly property int   acEdgesRadius: 60
    readonly property int   acButtonEdgesRadius: 15
    readonly property int   acButtonDimension: 45
    readonly property int   textAndDescriptionTextHeight: 65
    readonly property int   textAndDescriptionTextWidth: 100
    readonly property int   textAndDescriptionTextWidthBig: 180


    //font size
    readonly property int   fontSizeAcDescription: 10
    readonly property int   fontSizeAcMainTextDataVis: 18
    readonly property int   fontSizeAcMainText: 20
    readonly property int   fontSizeAcSubText: 18
    readonly property int   fontSizeAcSubTitle: 30
    readonly property int   fontSizeAcTitle: 30

    //font stype
    readonly property string fontTypeAcMain: "Siemens AD Sans"

    //margins
    readonly property int    marginAcDeviceTextTop: 40

}



