//
// Created by lukas on 12/5/2021.
//

#ifndef CONTROLLERS_SCANNEDDATA_HPP
#define CONTROLLERS_SCANNEDDATA_HPP
////OPENCV related
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
////

#include <cm-lib_global.h>
#include <data/string-decorator.h>
#include <QObject>
#include <QtCharts>


#include <data/entity.h>
#include <data/entity-collection.h>

#include <cstdint>
#include <utility>
#include <vector>
#include <QImage>
#include "../controllers/LowLevelFunctionality/Common/CustomEnumTypes.hpp"
#include "../controllers/LowLevelFunctionality/Common/Translators.hpp"

namespace ac {
namespace models {

//using namespace QtCharts;

class CMLIB_EXPORT ScannedData : public cm::data::Entity {
    //values
    Q_OBJECT
    Q_PROPERTY( QString                    ui_filename READ get_ui_filename                       NOTIFY data_changed)
    Q_PROPERTY( int                        ui_out1     MEMBER out1                                NOTIFY data_changed)
    Q_PROPERTY( int                        ui_out2     MEMBER out2                                NOTIFY data_changed)
    Q_PROPERTY( int                        ui_out3     MEMBER out3                                NOTIFY data_changed)
    Q_PROPERTY( int                        ui_outA     MEMBER outA                                NOTIFY data_changed)
    Q_PROPERTY( QString                    ui_result   READ   get_ui_result                       NOTIFY data_changed)
    Q_PROPERTY( QLineSeries*               ui_profile  READ   get_ui_profile WRITE set_ui_profile NOTIFY data_changed)

    //advance measurement
    Q_PROPERTY( QString  ui_isLongitudinalCrossSectionReady READ   get_ui_longitudinalCrossSectionReadiness NOTIFY data_changed)
    Q_PROPERTY( QString  ui_isTransverseCrossSectionReady   READ   get_ui_transverseCrossSectionReadiness   NOTIFY data_changed)
    Q_PROPERTY( QString  ui_isCameraBasicPhotoReady         READ   get_ui_cameraBasicPhotoReadiness         NOTIFY data_changed)
    Q_PROPERTY( QString  ui_isCameraCrossSectionPhotoReady  READ   get_ui_cameraCrossSectionPhotoReadiness  NOTIFY data_changed)

    //profile chart's look
    Q_PROPERTY( int ui_xAxisMin        MEMBER   xAxisMin        NOTIFY data_changed)
    Q_PROPERTY( int ui_xAxisMax        MEMBER   xAxisMax        NOTIFY data_changed)
    Q_PROPERTY( int ui_xAxisTickCount  MEMBER   xAxisTickCount  NOTIFY data_changed)

    Q_PROPERTY( int ui_yAxisMin        MEMBER   yAxisMin        NOTIFY data_changed)
    Q_PROPERTY( int ui_yAxisMax        MEMBER   yAxisMax        NOTIFY data_changed)
    Q_PROPERTY( int ui_yAxisTickCount  MEMBER   yAxisTickCount  NOTIFY data_changed)

    Q_PROPERTY( bool ui_isScannedDataReadyToAnalyze READ isScannedDataReadyToAnalyze NOTIFY data_changed)
    Q_PROPERTY( bool ui_isScannedDataReadyToSave    READ isScannedDataReadyToSave    NOTIFY data_changed)

public:

    ////CONNECTIONS


    ////INTEGRAL PARTS OF CLASS
    explicit ScannedData(QObject *parent = nullptr);
    ScannedData(QObject* parent, const QJsonObject& json);
    cm::data::StringDecorator* name{nullptr};

    ////DATA RELATED CMD
    void updateFinalResult();

    ////Profilometer
    std::string fileName {"Measurement"};
    int     out1 {0};
    int     out2 {0};
    int     out3 {0};
    int     outA {0};
    std::vector<std::pair<int,int>> profileData {};
    std::vector<double> profileCoefficients {};
    ScanResult resultProfilometer {ScanResult::Unrecognized};

    ////Camera
    cv::Mat cameraImage {};
    ScanResult resultCamera {ScanResult::Unrecognized};


    ////Overall Result
    ScanResult finalResult {ScanResult::Unrecognized};

    ////Chart value
    QLineSeries* get_ui_profile() const;
    void set_ui_profile(QLineSeries *series);
    void update_ui_profile();

    QString get_ui_result();
    QString get_ui_filename();

    ////Chart advance value
    QString get_ui_longitudinalCrossSectionReadiness();
    QString get_ui_transverseCrossSectionReadiness();
    QString get_ui_cameraBasicPhotoReadiness();
    QString get_ui_cameraCrossSectionPhotoReadiness();

    ////Chart look
    int xAxisMin {0};
    int xAxisMax {1};
    int xAxisTickCount {20};

    int yAxisMin {0};
    int yAxisMax {1};
    int yAxisTickCount {20};

    ////Advance View
    ScanResult resultProfilometerLongitudinalCrossSection {ScanResult::Unrecognized};
    std::vector<std::pair<int,int>> profileDataLongitudinalCrossSection {};
    std::vector<double> longitudinalProfileCoefficients {};

    ScanResult resultProfilometerTransverseCrossSection   {ScanResult::Unrecognized};
    std::vector<std::pair<int,int>> profileDataTransverseCrossSection {};
    std::vector<double> transverseProfileCoefficients {};

    ScanResult resultCameraBasicPhoto                     {ScanResult::Unrecognized};
    cv::Mat cameraImageBasicPhoto {};

    ScanResult resultCameraCrossSectionPhoto              {ScanResult::Unrecognized};
    cv::Mat cameraImageCrossSectionPhoto {};


    ////UI Control
    bool isScannedDataReadyToAnalyze(){
        return (not profileDataLongitudinalCrossSection.empty()) and (not profileDataTransverseCrossSection.empty())
                and (not cameraImageBasicPhoto.empty()) and (not cameraImageCrossSectionPhoto.empty());
    }
    bool isScannedDataReadyToSave(){
        return (not longitudinalProfileCoefficients.empty()) and (not transverseProfileCoefficients.empty());
    }

    ////Managment
    void clearDataAndUpdateUi();

    ////debugging
    void printProfile();
    void printAxisLimits();


signals:
    void data_changed();
    void axis_limit_changed();
    void axis_tick_count_changed();

private:
    QLineSeries* convertedProfile; //It's created in qml, we have only reference here
    QMap<bool,QString> readinessInfoMap {{false,"Not Ready"},{true,"Ready"}};
    std::string defaultFileName {"Measurement"};
};
}
}

#endif //CONTROLLERS_SCANNEDDATA_HPP
