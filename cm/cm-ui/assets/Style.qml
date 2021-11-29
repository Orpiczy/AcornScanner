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

    //CM parameters
    readonly property real  cmChartHeight: 100
    readonly property real  cmChartWidth:  200
    readonly property real  cmRightColumnWidth: 100
    readonly property real  cmCoffeMakeButtonHeight: 50
    readonly property real  cmCoffeMakeButtonWidth: 180
    readonly property real  cmWarningOnOffBarHeight: 50
    readonly property real  cmWarningOnOffBarWidth: 120
    readonly property color colorCmChartEdges: "#4B2827"
    readonly property color colorCmChartBox: "#F5EBE4"
    readonly property color colorCmMilkCircleForeground: "#F8F8F8"
    readonly property color colorCmWaterCircleForeground: "#147AD6"
    readonly property color colorCmMilkCircleBackground: "#C7C8D0"

}



