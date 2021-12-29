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
    try
    {

    cv::Mat image;
    char keyPressed;
    cv::VideoCapture cam(CAMERA_ID_);

    cam.set(cv::CAP_PROP_FRAME_WIDTH, cameraResolution_.first);
    cam.set(cv::CAP_PROP_FRAME_HEIGHT, cameraResolution_.second);

    if (!cam.isOpened()) {
        LG_ERR("FAILURE - CAMERA COULD'T BE OPENED - CameraManager::openCameraView()");
    }

    int delay = 1000 / displayFrameRate_;
    while (true) {
        cam >> image;
        rotateImage(image);
        cv::imshow("CameraView (press q to exit)", image);
        keyPressed = cv::waitKey(delay);
        if(keyPressed == 'q'){
            cv::destroyAllWindows();
            break;
        }
    }

    cam.release();

    }
    catch(cv::Exception& e ){
        std::string errorMsg = e.what();
        LG_ERR("EXCEPTION CAUGHT - " + errorMsg + " - CameraManager::openCameraView()");
        std::terminate();
    }

    return 0;
}

cv::Mat CameraManager::getImage()
{
    try
    {

    cv::Mat image {};
    cv::VideoCapture cam(CAMERA_ID_);

    cam.set(cv::CAP_PROP_FRAME_WIDTH, cameraResolution_.first);
    cam.set(cv::CAP_PROP_FRAME_HEIGHT, cameraResolution_.second);

    if(not cam.isOpened()){
        LG_ERR("ERROR - PROGRAM WAS UNABLE TO OPEN CAMERA - CameraManager::getImage() - CAMERA_ID_ = ",CAMERA_ID_);
        cam.release();
        std::terminate();
        return {};
    }

    //first photo sometimes is corrupted
    for(int i = 0; i < imageRetake_; i++){
        cam >> image;
    }


    if(not image.empty()){
        LG_INF("SUCCESS - THE IMAGE WAS TAKEN AND THE RESULT IS NOT EMPTY - CameraManager::getImage()");
    }
    cam.release();

    rotateImage(image);

    return image;

    }
    catch(cv::Exception& e ){
        std::string errorMsg = e.what();
        LG_ERR("EXCEPTION CAUGHT - " + errorMsg + " - CameraManager::openCameraView()");
    }
    return {};
}


////HELPER
void CameraManager::rotateImage(cv::Mat& image, int rotationInDegrees)
{
    cv::Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    cv::Mat rotationMatix = cv::getRotationMatrix2D(center, rotationInDegrees, 1.0);
    cv::warpAffine(image, image, rotationMatix, image.size());

    //cropping
    if(rotationInDegrees == -90){

        int height = image.rows;
        int halfHeight = height / 2;
        int halfWidth = image.cols / 2;

        cv::Rect croppingRectangle(halfWidth - halfHeight, 0, height, height);
        image = image(croppingRectangle);
    }
}
////VARIABLES
CameraManager*            CameraManager::cam_ = nullptr;
const int                 CameraManager::CAMERA_ID_  = 0;
const int                 CameraManager::displayFrameRate_ = 30;
const int                 CameraManager::cameraRotation_ = -90;
const std::pair<int,int>  CameraManager::cameraResolution_ = {640,320};
const int                 CameraManager::imageRetake_ = 10;
const std::string         CameraManager::testImagePath_ = "E:/Dokumenty/AiR_rok_4/S7/EngineeringThesis/AcornScanner/"
                                                  "cm/cm-lib/source/controllers/LowLevelFunctionality/DeviceController/CameraManager/TestData/Acorn.jpg";

