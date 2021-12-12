import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.2
//custom modules
import assets 1.0
import components 1.0

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Client Management")

    Component.onCompleted: contentFrame.replace("qrc:/views/ACMasterView.qml");

    Connections {
        target: masterController.ui_navigationController
        onGoCreateClientView: contentFrame.replace("qrc:/views/CreateClientView.qml")
        onGoDashboardView: contentFrame.replace("qrc:/views/DashboardView.qml")
        onGoEditClientView: contentFrame.replace("qrc:/views/EditClientView.qml",
                                                 {selectedClient: client})
        onGoFindClientView: contentFrame.replace("qrc:/views/FindClientView.qml")
    }


    NavigationBar {
        id: navigationBar
    }


    StackView {
        id: contentFrame
        anchors{
            top: parent.top
            bottom: parent.bottom
            left: navigationBar.right
            right: parent.right
        }
        clip: tr
        initialItem: "qrc:/views/SplashView.qml"
    }

}
