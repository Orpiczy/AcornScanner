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
    int getAllData(ac::models::ScannedData& data){        
        for(auto device: deviceList){
            device -> addInfoToScannedData(data);
        }
        data.updateFinalResult();
        return 0;
    }

    int getAndSaveAllData(ac::models::ScannedData& data){
        std::string commonTimeStamp = FileSystemController::GetInstance()->getFullTimeStamp();
        data.fileName = commonTimeStamp;
        for(auto device: deviceList){
            device -> addInfoToScannedDataAndSaveItToDataBase(data,commonTimeStamp);
        }
        data.updateFinalResult();
        FileSystemController::GetInstance() -> addScanToDailyStatistic(data.finalResult);
        return 0;
    }

    int getCameraData(ac::models::ScannedData& data){
        CameraManager::GetInstance() -> addInfoToScannedData(data);
        return 0;
    }

    int getProfilometerData(ac::models::ScannedData& data){
        ProfilometerManager::GetInstance() -> addInfoToScannedData(data);
        return 0;
    }

protected:
    ////INTEGRAL PARTS OF CLASS
    explicit DeviceController(bool isLogInfoEnable = false, bool isLogErrorEnable = true)
            : SimpleLogger(isLogInfoEnable, isLogErrorEnable) {};

private:




    ////VARIABLES
public:
protected:
    static DeviceController* dvc_;
    std::vector<DeviceManager*> deviceList = {CameraManager::GetInstance(),ProfilometerManager::GetInstance()};
private:


};


#endif //CONTROLLERS_DEVICECONTROLLER_HPP
