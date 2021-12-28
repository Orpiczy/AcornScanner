#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "../../../models/scannedData.hpp"
#include "../BaseClasses/SimpleLogger.hpp"
#include "../Common/CustomEnumTypes.hpp"
#include "../Common/ControllersFlags.hpp"

class DataController: private SimpleLogger
{
////METHODS
public:
    ////INTEGRAL PARTS OF CLASS
    static DataController* GetInstance();

    DataController(DataController & other) = delete;
    void operator=(const DataController&) = delete;

    ///BASIC CMD

    ////ProfilometerData
    int analyzeMainProfileData(ac::models::ScannedData& data);
    int analyzeLongitudinalCrossSectionAndUpdateResult(ac::models::ScannedData& data);
    int analyzeTransverseCrossSectionAndUpdateResult(ac::models::ScannedData& data);

    ////CameraData
    int analyzeMainPhotoAndUpdateResult(ac::models::ScannedData& data);
    int analyzeBasicPhotoAndUpdateResult(ac::models::ScannedData& data);
    int analyzeCrossSectionPhotoAndUpdateResult(ac::models::ScannedData& data);

    int updateFinalResult(ac::models::ScannedData& data);

protected:

    ////INTEGRAL PARTS OF CLASS
    explicit DataController(bool isLogInfoEnable = true, bool isLogErrorEnable = true);

    ///BASIC CMD
    std::vector<double> getPolynomialCoefficients(std::vector<std::pair<int,int>>& pairsXY,int order = 3);

////VARIABLES
protected:
    static DataController* dc_;

};

#endif // DATACONTROLLER_H
