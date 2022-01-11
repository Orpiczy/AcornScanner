#include "profilometerDeviceUi.h"
#include "../controllers/LowLevelFunctionality/DeviceController/DeviceController.hpp"
#include "scannedData.hpp"
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
 ac::models::ScannedData testData;
 switch(DeviceController::GetInstance()->getProfilometerData(testData)){
     case 0:
         connectionStatus = "Connected";
         functionalStatus = "Available";
         break;
     default:
         connectionStatus = "Not Connected";
         functionalStatus = "Not Ready";
 }

 qDebug() << "updateProfilometerClicked()";
 emit device_status_change();
}
