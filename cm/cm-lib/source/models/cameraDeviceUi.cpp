#include "camerDeviceUi.h"
#include "../controllers/LowLevelFunctionality/DeviceController/DeviceController.hpp"
#include "scannedData.hpp"
#include <QDebug>
CameraDeviceUi::CameraDeviceUi(QObject *parent) : QObject(parent)
{


}

void CameraDeviceUi::updateStatus()
{
    /*
 *
 *
 *  IMPLEMENTATION - THIS IS ONLY STUB
 *
 *
 */
    //    connectionStatus = QString::fromStdString(ac::translators::getDeviceConnectionStatusName(DeviceConnectionStatus::Yes));
    //    functionalStatus = QString::fromStdString(ac::translators::getDeviceFuntionalStatusName(DeviceFunctionalStatus::Alright));
    ac::models::ScannedData testData;

    switch(DeviceController::GetInstance()->getCameraData(testData)){
        case 0:
            connectionStatus = "Connected";
            functionalStatus = "Available";
            break;
        default:
            connectionStatus = "Not Connected";
            functionalStatus = "Not Ready";
    }

    qDebug() << "CameraUpdateClicked";
    emit device_status_change();
}
