//
// Created by lukas on 12/5/2021.
//

#ifndef CONTROLLERS_CAMERAMANAGER_HPP
#define CONTROLLERS_CAMERAMANAGER_HPP
#include <cm-lib_global.h>

//// OPENCV RELATED
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
////

#include "../../BaseClasses/SimpleLogger.hpp"
#include "../../Common/CustomEnumTypes.hpp"
#include "../../Common/ControllersFlags.hpp"
#include "../../BaseClasses/DeviceManager.hpp"
#include "../../FileSystemController/FileSystem/FileSystemController.hpp"
#include <vector>
#include <QImage>

class CMLIB_EXPORT CameraManager : private SimpleLogger, public DeviceManager {
////METHODS
public:

////INTEGRAL PARTS OF CLASS
    static CameraManager* GetInstance();

    CameraManager(CameraManager
                  & other) = delete;

    void operator=(const CameraManager&) = delete;

////BASIC CMD
    int addInfoToScannedData(ac::models::ScannedData& data) override {
        if (not IS_CAMERA_AVAILABLE) {
            data.cameraImage = getImage();
            data.resultCamera = CAMERA_RESULT;
            data.finalResult = data.resultCamera == data.finalResult ? data.finalResult : ScanResult::Unrecognized;
            return 0;
        }
        /*
         *
         *
         *  IMPLEMENTATION
         *
         *
         */
        return -1;
    }

    int addInfoToScannedDataAndSaveItToDataBase(ac::models::ScannedData& data) override {
        if (not IS_CAMERA_AVAILABLE) {
            data.cameraImage = getImage();
            data.resultCamera = CAMERA_RESULT;
            data.finalResult = data.resultCamera == data.finalResult ? data.finalResult : ScanResult::Unrecognized;
            FileSystemController::GetInstance()->addCameraImageToCategorizedDataBase(data.resultCamera, data.cameraImage);
            return 0;
        }
        /*
         *
         *
         *  IMPLEMENTATION
         *
         *
         */
        return -1;
    }
////CONTROLLER CONNECTION
    int checkFunctionalityAndUpdateStatus() override {return 0;}

protected:

////INTEGRAL PARTS OF CLASS
    explicit CameraManager(bool isLogInfoEnable = true, bool isLogErrorEnable = true)
            : SimpleLogger(isLogInfoEnable, isLogErrorEnable) {};

////BASIC CMD
    cv::Mat getImage();
private:




////VARIABLES
public:
protected:
    static CameraManager* cam_;
private:
    const static int     CAMERA_ID_;
    const static cv::Mat testImage;
};


#endif //CONTROLLERS_CAMERAMANAGER_HPP
