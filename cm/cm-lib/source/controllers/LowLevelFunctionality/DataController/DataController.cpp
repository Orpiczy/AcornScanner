#include "DataController.h"
#include "PolynomialRegression.h"

////INTEGRAL PARTS OF CLASS

DataController *DataController::GetInstance()
{
    if(dc_ == nullptr){
        dc_ = new DataController;
    }
    return dc_;
}

DataController::DataController(bool isLogInfoEnable, bool isLogErrorEnable)
    : SimpleLogger(isLogInfoEnable, isLogErrorEnable) {}

////BASIC CMD

int DataController::analyzeMainProfileData(ac::models::ScannedData &data){
    if(data.profileData.empty()){
        LG_INF("WARNING - ANALYSIS IS NOT AVAILABLE - PROFILE DATA IS EMPTY - DataController::analyzeMainProfileData");
        return -1;
    }

    data.profileCoefficients = getPolynomialCoefficients(data.profileData);

    /*
     *
     *
     *  IMPLEMENTATION
     *
     *
     */

    LG_DBG("INFO - IN METHOD - DataController::analyzeMainProfileData()");
    data.resultProfilometer = ScanResult::Unrecognized;
    return 0;
}

int DataController::analyzeLongitudinalCrossSectionAndUpdateResult(ac::models::ScannedData &data){
    if(data.profileDataLongitudinalCrossSection.empty()){
        LG_INF("WARNING - ANALYSIS IS NOT AVAILABLE - PROFILE DATA OF LONGITUDINAL CROSS SECTION IS EMPTY - DataController::analyzeLongitudinalCrossSectionAndUpdateResult");
        return -1;
    }

    data.longitudinalProfileCoefficients = getPolynomialCoefficients(data.profileDataLongitudinalCrossSection);

    /*
     *
     *
     *  IMPLEMENTATION
     *
     *
     */

    LG_DBG("INFO - IN METHOD - DataController::analyzeLongitudinalCrossSection()");
    data.resultProfilometerLongitudinalCrossSection = ScanResult::Unrecognized;
    return 0;
}

int DataController::analyzeTransverseCrossSectionAndUpdateResult(ac::models::ScannedData &data){
    if(data.profileDataTransverseCrossSection.empty()){
       LG_INF("WARNING - ANALYSIS IS NOT AVAILABLE - PROFILE DATA OF TRANSVERSE CROSS SECTION IS EMPTY - DataController::analyzeTransverseCrossSectionAndUpdateResult");
       return -1;
    }

    data.transverseProfileCoefficients = getPolynomialCoefficients(data.profileDataTransverseCrossSection);

    /*
     *
     *
     *  IMPLEMENTATION
     *
     *
     */

    LG_DBG("INFO - IN METHOD - DataController::analyzeTransverseCrossSection()");
    data.resultProfilometerTransverseCrossSection = ScanResult::Unrecognized;
    return 0;
}

int DataController::analyzeMainPhotoAndUpdateResult(ac::models::ScannedData &data){

    /*
     *
     *
     *  IMPLEMENTATION
     *
     *
     */

    LG_DBG("INFO - IN METHOD - DataController::analyzeMainPhotoAndUpdateResult()");
    data.resultCamera = ScanResult::Unrecognized;
    return 0;

}

int DataController::analyzeBasicPhotoAndUpdateResult(ac::models::ScannedData &data){

    /*
     *
     *
     *  IMPLEMENTATION
     *
     *
     */

    LG_DBG("INFO - IN METHOD - DataController::analyzeBasicPhoto()");
    data.resultCameraBasicPhoto = ScanResult::Unrecognized;
    return 0;
}

int DataController::analyzeCrossSectionPhotoAndUpdateResult(ac::models::ScannedData &data){

    /*
     *
     *
     *  IMPLEMENTATION
     *
     *
     */

    LG_DBG("INFO - IN METHOD - DataController::analyzeBasicPhoto()");
    data.resultCameraCrossSectionPhoto = ScanResult::Unrecognized;
    return 0;
}

int DataController::updateFinalResult(ac::models::ScannedData &data)
{

    /*
     *
     *
     *  IMPLEMENTATION
     *
     *
     */

    LG_DBG("INFO - IN METHOD - DataController:::updateFinalResult()");
    data.finalResult = ScanResult::Unhealthy;
    return 0;
}

std::vector<double> DataController::getPolynomialCoefficients(std::vector<std::pair<int, int> > &pairsXY, int order)
{
    std::vector<double> x = {};
    std::vector<double> y = {};
    std::vector<double> coeffs = {};

    for(auto& pair: pairsXY){
        x.push_back(pair.first);
        y.push_back(pair.second);
    }

    PolynomialRegression<double> pr;
    if(pr.fitIt(x,y,order,coeffs)){
        LG_INF("SUCCESS - POLYNOMIAL FITTING WAS SUCCESSFUL - DataController::getPolynomialCoefficients");
        if(isLogDebugEnable){
            pr.printCoeffs(coeffs);
            pr.getYfromXAndPolynomialCoeffs(x,coeffs,y);
        }
        return coeffs;

    }

    LG_ERR("FAILURE - POLYNOMIAL FITTING FAILED - DataController::getPolynomialCoefficients");
    return {};

}
////VARIABLES
DataController* DataController::dc_ = nullptr;
