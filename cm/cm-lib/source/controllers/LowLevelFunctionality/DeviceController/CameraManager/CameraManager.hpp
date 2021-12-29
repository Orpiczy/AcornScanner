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

    CameraManager(CameraManager & other) = delete;

    void operator=(const CameraManager&) = delete;

    ////BASIC CMD
    cv::Mat getImage();

    int openCameraView();

    int addInfoToScannedData(ac::models::ScannedData& data) override;

    int addInfoToScannedDataAndSaveItToDataBase(ac::models::ScannedData& data,std::string commonTimeStamp = {}) override;

    ////CONTROLLER CONNECTION
    int checkFunctionalityAndUpdateStatus() override {return 0;}

protected:

    ////INTEGRAL PARTS OF CLASS
    explicit CameraManager(bool isLogInfoEnable = true, bool isLogErrorEnable = true);
private:
    ////HELPERS
    void rotateImage(cv::Mat& image,int rotationInDegrees = cameraRotation_);


    ////VARIABLES

protected:
    static CameraManager* cam_;

private:
    const static int CAMERA_ID_;
    const static std::string testImagePath_;
    const static int displayFrameRate_;
    const static std::pair<int,int> cameraResolution_;
    const static int cameraRotation_;
    const static int imageRetake_; // defines how many pictures are taken before saving the final one
    cv::Mat testImage;
};


#endif //CONTROLLERS_CAMERAMANAGER_HPP
