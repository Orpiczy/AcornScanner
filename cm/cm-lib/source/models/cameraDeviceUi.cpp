#include "camerDeviceUi.h"

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
    connectionStatus = "Yes";
    functionalStatus = "Alright";
    emit device_status_change();
}
