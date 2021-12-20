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
const cv::Mat CameraManager::testImage = {};
const int     CameraManager::CAMERA_ID_  = 0;

