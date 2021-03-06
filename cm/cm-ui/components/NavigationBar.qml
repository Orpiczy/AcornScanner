import QtQuick 2.15
import assets 1.0

Item{

    property bool isCollapsed: true

    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }

    width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.heightNavigationBarExpanded

    Rectangle {
        anchors.fill: parent
        color: Style.colorAcNavigationBarBackground

        Column {
            width: parent.width
            visible: !isCollapsed
            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
                onNavigationButtonClicked: masterController.ui_navigationController.goACSettingsView();
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Client"
                onNavigationButtonClicked: masterController.ui_navigationController.goACMasterView();
            }

        }
    }
}

