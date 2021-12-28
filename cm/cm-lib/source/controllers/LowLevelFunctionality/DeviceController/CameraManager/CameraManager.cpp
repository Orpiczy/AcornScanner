//
// Created by lukas on 12/5/2021.
//

#include "CameraManager.hpp"

////INTEGRAL PARTS OF CLASS

CameraManager* CameraManager::GetInstance() {
    if (cam_ == nullptr) {
        cam_= new CameraManager();
    }
    return cam_;
}

CameraManager::CameraManager(bool isLogInfoEnable, bool isLogErrorEnable)
    : SimpleLogger(isLogInfoEnable, isLogErrorEnable) {
    //acorn image, if commented program saves nothing thanks to check in fileSystemController
    testImage = cv::imread(testImagePath_, cv::IMREAD_COLOR );
}

////BASIC CMDS
int CameraManager::addInfoToScannedData(ac::models::ScannedData &data) {
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

int CameraManager::addInfoToScannedDataAndSaveItToDataBase(ac::models::ScannedData &data, std::string commonTimeStamp) {
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

int CameraManager::openCameraView(){
    cv::Mat image;
    char keyPressed;
    cv::VideoCapture cam(CAMERA_ID_);

    if (!cam.isOpened()) {
        LG_ERR("FAILURE - CAMERA COULD'T BE OPENED - CameraManager::openCameraView()");
    }

    int delay = 1000 / displayFrameRate_;
    while (true) {
        cam >> image;
        cv::imshow("CameraView (press q to exit)", image);
        keyPressed = cv::waitKey(delay);
        if(keyPressed == 'q'){
            cv::destroyAllWindows();
            break;
        }
    }

    return 0;
}

cv::Mat CameraManager::getImage()
{
    cv::Mat image {};
    cv::VideoCapture cam(CAMERA_ID_);
    if(not cam.isOpened()){
        LG_ERR("ERROR - PROGRAM WAS UNABLE TO OPEN CAMERA - CameraManager::getImage() - CAMERA_ID_ = ",CAMERA_ID_);
        cam.release();
        return {};
    }
    cam >> image;

    if(not image.empty()){
        LG_INF("SUCCESS - THE IMAGE WAS TAKEN AND THE RESULT IS NOT EMPTY - CameraManager::getImage()");
    }
    cam.release();
    return image;
}

////VARIABLES
CameraManager* CameraManager::cam_ = nullptr;
const int      CameraManager::CAMERA_ID_  = 0;
const int      CameraManager::displayFrameRate_ = 30;
const std::string CameraManager::testImagePath_ = "E:/Dokumenty/AiR_rok_4/S7/EngineeringThesis/AcornScanner/"
                                                 "cm/cm-lib/source/controllers/LowLevelFunctionality/DeviceController/CameraManager/TestData/Acorn.jpg";

