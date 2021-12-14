#include "profilometerDeviceUi.h"

ProfilometerDeviceUi::ProfilometerDeviceUi(QObject *parent) : QObject(parent)
{

}

void ProfilometerDeviceUi::updateStatus()
{
/*
 *
 *
 *  IMPLEMENTATION - THIS IS ONLY STUB
 *
 *
 */
// connectionStatus = QString::fromStdString(ac::translators::getDeviceConnectionStatusName(DeviceConnectionStatus::Yes));
// functionalStatus = QString::fromStdString(ac::translators::getDeviceFuntionalStatusName(DeviceFunctionalStatus::Alright));
 qDebug() << "updateProfilometerClicked()";
 connectionStatus = "Yes";
 functionalStatus = "Alright";
 emit device_status_change();
}
