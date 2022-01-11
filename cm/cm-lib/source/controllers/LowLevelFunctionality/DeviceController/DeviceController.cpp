//
// Created by lukas on 12/5/2021.
//

#include "DeviceController.hpp"

////INTEGRAL PARTS OF CLASS

DeviceController* DeviceController::GetInstance() {
    if (dvc_ == nullptr) {
        dvc_= new DeviceController();
    }
    return dvc_;
}

////CMD
///
int DeviceController::getAllData(ac::models::ScannedData &data){
    for(auto device: deviceList){
        device -> addInfoToScannedData(data);
    }
    data.updateFinalResult();
    return 0;
}

int DeviceController::getAndSaveAllData(ac::models::ScannedData &data){
    std::string commonTimeStamp = FileSystemController::GetInstance()->getFullTimeStamp();
    data.fileName = commonTimeStamp;
    for(auto device: deviceList){
        device -> addInfoToScannedDataAndSaveItToDataBase(data,commonTimeStamp);
    }
    data.updateFinalResult();
    FileSystemController::GetInstance() -> addScanToDailyStatistic(data.finalResult);
    return 0;
}

int DeviceController::getCameraData(ac::models::ScannedData &data){
    return CameraManager::GetInstance() -> addInfoToScannedData(data);
}

int DeviceController::getProfilometerData(ac::models::ScannedData &data){
    return ProfilometerManager::GetInstance() -> addInfoToScannedData(data);
}

int DeviceController::generateRaportAndSaveAdvanceMeasurement(ac::models::ScannedData &data){
    std::string commonTimeStamp = FileSystemController::GetInstance()->getFullTimeStamp();
    auto fs = FileSystemController::GetInstance();

    //Profilometer
    fs -> addProfilometerScanDataToAdvanceMeasurement(data.finalResult,profileTypes_.at(0),
                                                      data.longitudinalProfileCoefficients,
                                                      data.profileDataLongitudinalCrossSection,
                                                      commonTimeStamp);
    fs -> addProfilometerScanDataToAdvanceMeasurement(data.finalResult,profileTypes_.at(1),
                                                      data.transverseProfileCoefficients,
                                                      data.profileDataTransverseCrossSection,
                                                      commonTimeStamp);

    //Camera
    fs -> addCameraImageToAdvanceMeasurement(data.finalResult,photoTypes_.at(0),
                                             data.cameraImageBasicPhoto,
                                             commonTimeStamp);
    fs -> addCameraImageToAdvanceMeasurement(data.finalResult,photoTypes_.at(1),
                                             data.cameraImageCrossSectionPhoto,
                                             commonTimeStamp);

    //Generate raport
    fs -> createAndAddAdvanceDataRaport(data.finalResult,
                                        data.resultProfilometerLongitudinalCrossSection,
                                        data.resultProfilometerTransverseCrossSection,
                                        data.resultCameraBasicPhoto,
                                        data.resultCameraCrossSectionPhoto,
                                        commonTimeStamp);
    //Save final result
    fs -> addScanToDailyStatistic(data.finalResult);

    return 0;

}

////VARIABLES
DeviceController* DeviceController::dvc_ = nullptr;
const std::vector<std::string> DeviceController::profileTypes_ = {"Longitudinal","Transverse"};
const std::vector<std::string> DeviceController::photoTypes_ = {"Basic","Cross Section"};



