#include "scannedData.hpp"
#include "../controllers/LowLevelFunctionality/DeviceController/DeviceController.hpp"
#include <limits.h>
namespace ac {
namespace models {
////INTEGRAL PARTS OF CLASS
ScannedData::ScannedData(QObject *parent) : Entity(parent, "ScannedData")
{
    name = static_cast<cm::data::StringDecorator*>(addDataItem(new cm::data::StringDecorator(this, "recentlyScannedData", "dataInfo")));
    fileName = "ABCD";
    /*
     *
     *
     *  IMPLEMENTATION - PARSING TO JSON
     *
     *
     */
}

ScannedData::ScannedData(QObject *parent, const QJsonObject &json): ScannedData(parent)
{
    update(json);
}

////DATA RELATED CMD
void ScannedData::updateFinalResult()
{
    if(resultProfilometer == resultCamera){
        finalResult = resultProfilometer;
    }else{
        finalResult = ScanResult::Unrecognized;
    }
}

////CHART value
QLineSeries* ScannedData::get_ui_profile() const
{
    return convertedProfile;
}

void ScannedData::set_ui_profile(QLineSeries *ui_profile)
{
    convertedProfile = ui_profile;
}

void ScannedData::update_ui_profile(){
     //minimal values are standarize in profilometerManagerto be equal 0
    convertedProfile->clear();

    yAxisMax = std::numeric_limits<int>::min();
    xAxisMax = std::numeric_limits<int>::min();
//    yAxisMin = std::numeric_limits<int>::max();
//    xAxisMin = std::numeric_limits<int>::max();

    for(auto pair: profileData){
        auto x = pair.first;
        auto y = pair.second;
        convertedProfile->append(x,y);

        //axis limits
//        xAxisMin = x < xAxisMin ? x : xAxisMin;
//        yAxisMin = y < yAxisMin ? y : yAxisMin;
        xAxisMax = x > xAxisMax ? x : xAxisMax;
        yAxisMax = y > yAxisMax ? y : yAxisMax;
    }

    //printProfile();

    //padding
//    float padding = 0.1;
//    auto xDiff = xAxisMax - xAxisMin;
//    auto yDiff = yAxisMax - yAxisMin;
//    yAxisMin -= padding*yDiff;
//    xAxisMin -= padding*xDiff;
//    xAxisMax += padding*xDiff;
//    yAxisMax += padding*yDiff;



    int precision = 100;
    xAxisMax = (xAxisMax / precision + 1) * precision;
    yAxisMax = (yAxisMax / precision + 1) * precision;
    if(xAxisMax > yAxisMax){
        yAxisMax = xAxisMax;
    }else{
        xAxisMax = yAxisMax;
    }
    yAxisMin = 0;
    xAxisMin = 0;
    printAxisLimits();
    emit data_changed();
}

////CHART value
QString  ScannedData::get_ui_result()
{
    return QString::fromStdString(ac::translators::getResultName(finalResult));
}

QString ScannedData::get_ui_filename()
{
    return QString::fromStdString(fileName);
}

////Chart advance value
QString ScannedData::get_ui_longitudinalCrossSectionReadiness()
{
    return readinessInfoMap[not profileDataLongitudinalCrossSection.empty()];
}

QString ScannedData::get_ui_transverseCrossSectionReadiness()
{
    return readinessInfoMap[not profileDataTransverseCrossSection.empty()];
}

QString ScannedData::get_ui_cameraBasicPhotoReadiness()
{
    return readinessInfoMap[not cameraImageBasicPhoto.empty()];
}

QString ScannedData::get_ui_cameraCrossSectionPhotoReadiness()
{
    return readinessInfoMap[not cameraImageCrossSectionPhoto.empty()];
}



////Managment
void ScannedData::clearDataAndUpdateUi()
{
    out1 = out2 = out3 = outA = 0 ;
    profileData = profileDataLongitudinalCrossSection = profileDataTransverseCrossSection = {};
    profileCoefficients = longitudinalProfileCoefficients = trasverseProfileCoefficients = {};
    resultProfilometer = resultProfilometerLongitudinalCrossSection = resultProfilometerTransverseCrossSection = ScanResult::Unrecognized;



    cameraImage = cameraImageBasicPhoto = cameraImageCrossSectionPhoto = cv::Mat {};
    resultCamera = resultCameraBasicPhoto = resultCameraCrossSectionPhoto = ScanResult::Unrecognized;

    update_ui_profile();

    fileName = "";
    finalResult = ScanResult::Unrecognized;
    xAxisMin = yAxisMin = 0;
    xAxisMax = yAxisMax = 0;
    xAxisTickCount = yAxisTickCount = 20;

    emit data_changed();

}


////debugging
void ScannedData::printProfile(){
    qDebug()<<"Printing Profile, profile size:"<<profileData.size();
    for(auto pair: profileData){
        qDebug()<<"x: "<<pair.first<<", y: "<<pair.second;
    }
}

void ScannedData::printAxisLimits(){
    qDebug()<<"xmin : "<<xAxisMin;
    qDebug()<<"xmax : "<<xAxisMax;
    qDebug()<<"ymin : "<<yAxisMin;
    qDebug()<<"ymax : "<<yAxisMax;
}


}
}
