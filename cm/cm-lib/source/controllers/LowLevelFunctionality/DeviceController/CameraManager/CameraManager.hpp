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
        if (IS_CAMERA_AVAILABLE) {
            data.cameraImage = getImage();
        }else{
            data.cameraImage = testImage;
        }

        if(IS_CAMERA_RESULT_CHECK_ENABLED){

            /*
             *
             *
             *  IMPLEMENTATION
             *
             *
             */

        }else{
            data.resultCamera = CAMERA_RESULT;
        }
        return 0;
    }

    int addInfoToScannedDataAndSaveItToDataBase(ac::models::ScannedData& data,std::string commonTimeStamp = {}) override {
        if (IS_CAMERA_AVAILABLE) {
            data.cameraImage = getImage();
        }else{
            data.cameraImage = testImage;
        }

        if(IS_CAMERA_RESULT_CHECK_ENABLED){

            /*
             *
             *
             *  IMPLEMENTATION
             *
             *
             */

        }else{
            data.resultCamera = CAMERA_RESULT;
        }


        FileSystemController::GetInstance()->addCameraImageToCategorizedDataBase(data.resultCamera, data.cameraImage, commonTimeStamp);
        return 0;
    }
    ////CONTROLLER CONNECTION
    int checkFunctionalityAndUpdateStatus() override {return 0;}

protected:

    ////INTEGRAL PARTS OF CLASS
    explicit CameraManager(bool isLogInfoEnable = true, bool isLogErrorEnable = true);;

    ////BASIC CMD
    cv::Mat getImage();
private:


    ////VARIABLES
public:
protected:
    static CameraManager* cam_;
private:
    const static int CAMERA_ID_;
    const static std::string testImagePath;
    cv::Mat testImage;
};


#endif //CONTROLLERS_CAMERAMANAGER_HPP
