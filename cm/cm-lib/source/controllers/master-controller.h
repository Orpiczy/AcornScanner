#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <opencv2/opencv.hpp>

#include <QObject>
#include <QScopedPointer>
#include <QString>
#include <cm-lib_global.h>
#include <controllers/navigation-controller.h>
#include <controllers/command-controller.h>
#include <models/scannedData.hpp>
#include <models/dailyStatisticsData.h>
#include <models/camerDeviceUi.h>
#include <models/profilometerDeviceUi.h>
namespace cm {
namespace controllers {

using ScannedData = ac::models::ScannedData;
using DailyStatisticsData = ac::models::DailyStatisticsData;

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
//    we are adding here namespace info because it is access from ui side
    Q_PROPERTY( cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY( cm::controllers::CommandController*    ui_commandController    READ commandController    CONSTANT )
    Q_PROPERTY( ac::models::ScannedData*               ui_scannedData          READ recentlyScannedData  CONSTANT )
    Q_PROPERTY( ac::models::DailyStatisticsData*       ui_dailyData            READ obtainedDailyStatisticsData  CONSTANT )
    Q_PROPERTY( CameraDeviceUi*                        ui_cameraDevice         READ cameraDeviceModel    CONSTANT)
    Q_PROPERTY( ProfilometerDeviceUi*                  ui_profilometerDevice   READ profilometerDeviceModel CONSTANT)



public:
    ////INTEGRAL PARTS OF CLASS
    explicit MasterController(QObject* parent = nullptr);
    ~MasterController();

    ////CMD
    void measureUpdateAndSaveData();
    void measureAndSaveScannedData();

    //// VARIABLES
    NavigationController* navigationController();
    CommandController* commandController();
    ScannedData *recentlyScannedData();
    DailyStatisticsData *obtainedDailyStatisticsData();
    CameraDeviceUi      *cameraDeviceModel();
    ProfilometerDeviceUi *profilometerDeviceModel();

public slots:
    void onMeasureButtonClicked();
    void onMeasureLongitudinalCrossSectionButtonClicked();
    void onMeasureTransverseCrossSectionButtonClicked();
    void onTakeBasicPhotoButtonClicked();
    void onTakeCrossSectionPhotoClicked();
    void onCameraViewButtonClicked();
    void onAnalyzeButtonClicked();
    void onSaveButtonClicked();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;


};
}}
#endif
