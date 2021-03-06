//
// Created by lukas on 12/5/2021.
//

#ifndef CONTROLLERS_DEVICECONTROLLER_HPP
#define CONTROLLERS_DEVICECONTROLLER_HPP
#include <cm-lib_global.h>

#include "../BaseClasses/SimpleLogger.hpp"
#include "../Common/CustomEnumTypes.hpp"
#include "CameraManager/CameraManager.hpp"
#include "ProfilometerManager/ProfilometerManager.hpp"
#include "../../../models/scannedData.hpp"

class CMLIB_EXPORT DeviceController  : private SimpleLogger {
////METHODS
public:

    ////INTEGRAL PARTS OF CLASS
    static DeviceController* GetInstance();

    DeviceController(DeviceController& other) = delete;

    void operator=(const DeviceController&) = delete;

    ////CMD
    int getAllData(ac::models::ScannedData& data);

    int getAndSaveAllData(ac::models::ScannedData& data);

    int getCameraData(ac::models::ScannedData& data);

    int getProfilometerData(ac::models::ScannedData& data);

    int generateRaportAndSaveAdvanceMeasurement(ac::models::ScannedData& data);

protected:
    ////INTEGRAL PARTS OF CLASS
    explicit DeviceController(bool isLogInfoEnable = false, bool isLogErrorEnable = true)
            : SimpleLogger(isLogInfoEnable, isLogErrorEnable) {};

private:




    ////VARIABLES
public:
protected:
    static DeviceController* dvc_;
    static const std::vector<std::string> profileTypes_;
    static const std::vector<std::string> photoTypes_;
    std::vector<DeviceManager*> deviceList = {CameraManager::GetInstance(),ProfilometerManager::GetInstance()};

private:


};


#endif //CONTROLLERS_DEVICECONTROLLER_HPP
