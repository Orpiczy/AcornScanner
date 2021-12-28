#include "master-controller.h"
#include "LowLevelFunctionality/DeviceController/DeviceController.hpp"
#include "LowLevelFunctionality/DataController/DataController.h"

namespace cm {
namespace controllers {
////INTEGRAL PARTS OF CLASS
class MasterController::Implementation
{ public:
    Implementation(MasterController* _masterController)
        : masterController(_masterController)
    {
        navigationController = new NavigationController(masterController);
        commandController = new CommandController(masterController);
        recentlyScannedData = new ScannedData(masterController);
        obtainedDailyStatisticsData = new DailyStatisticsData(masterController);
        cameraDeviceModel = new CameraDeviceUi(masterController);
        profilometerDeviceModel = new ProfilometerDeviceUi(masterController);

    }
    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController* commandController{nullptr};
    QString welcomeMessage = "This is MasterController to Major Tom";
    ScannedData* recentlyScannedData{nullptr};
    DailyStatisticsData* obtainedDailyStatisticsData {nullptr};
    CameraDeviceUi* cameraDeviceModel {nullptr};
    ProfilometerDeviceUi* profilometerDeviceModel {nullptr};
};
MasterController::MasterController(QObject* parent)
    : QObject(parent)
{
    implementation.reset(new Implementation(this));
}
MasterController::~MasterController()
{}


////CMD
void MasterController::measureUpdateAndSaveData()
{
    measureAndSaveScannedData();
    obtainedDailyStatisticsData()->updateDailyData();
    //change signal is emitted in dailyStatistic implementation
}

void MasterController::measureAndSaveScannedData()
{
    DeviceController::GetInstance()->getAndSaveAllData(*recentlyScannedData());
    recentlyScannedData()->update_ui_profile();
}

////SLOTS
void MasterController::onMeasureButtonClicked()
{
    qDebug()<<"onMeasureButtonClicked() was initiated ";
    measureUpdateAndSaveData();
}

void MasterController::onMeasureLongitudinalCrossSectionButtonClicked()
{
    qDebug()<<"onMeasureLongitudinalCrossSectionButtonClicked()";
    DeviceController::GetInstance()->getProfilometerData(*recentlyScannedData());
    recentlyScannedData()->profileDataLongitudinalCrossSection = recentlyScannedData()->profileData;
    recentlyScannedData()->update_ui_profile();
    emit recentlyScannedData()->data_changed();
}

void MasterController::onMeasureTransverseCrossSectionButtonClicked()
{
    qDebug()<<"onMeasureTransverseCrossSectionButtonClicked()";
    DeviceController::GetInstance()->getProfilometerData(*recentlyScannedData());
    recentlyScannedData()->profileDataTransverseCrossSection = recentlyScannedData()->profileData;
    recentlyScannedData()->update_ui_profile();
    emit recentlyScannedData()->data_changed();
}

void MasterController::onTakeBasicPhotoButtonClicked()
{
    qDebug()<<"onTakeBasicPhotoButtonClicked()";
    DeviceController::GetInstance()->getCameraData(*recentlyScannedData());
    recentlyScannedData()->cameraImageBasicPhoto = recentlyScannedData()->cameraImage;
    emit recentlyScannedData()->data_changed();
}

void MasterController::onTakeCrossSectionPhotoClicked()
{
    qDebug()<<"onTakeCrossSectionPhotoClicked()";
    DeviceController::GetInstance()->getCameraData(*recentlyScannedData());
    recentlyScannedData()->cameraImageCrossSectionPhoto = recentlyScannedData()->cameraImage;
    emit recentlyScannedData()->data_changed();
}

void MasterController::onCameraViewButtonClicked()
{
    qDebug()<<"onCameraViewButtonClicked()";
    CameraManager::GetInstance()->openCameraView();
}

void MasterController::onAnalyzeButtonClicked()
{
    auto dataController = DataController::GetInstance();
    dataController->analyzeLongitudinalCrossSectionAndUpdateResult(*recentlyScannedData());
    dataController->analyzeTransverseCrossSectionAndUpdateResult(*recentlyScannedData());
    dataController->analyzeBasicPhotoAndUpdateResult(*recentlyScannedData());
    dataController->analyzeCrossSectionPhotoAndUpdateResult(*recentlyScannedData());
    dataController->updateFinalResult(*recentlyScannedData());

    qDebug()<<"onAnalyzeButtonClicked()";
}

void MasterController::onSaveButtonClicked()
{

    DeviceController::GetInstance()->generateRaportAndSaveAdvanceMeasurement(*recentlyScannedData());
    delete recentlyScannedData();
    recentlyScannedData()->clearDataAndUpdateUi();

    qDebug()<<"onSaveButtonClicked()";
}



//// VARIABLES -> setters and getters
NavigationController* MasterController::navigationController()
{
    return implementation->navigationController;
}

CommandController *MasterController::commandController()
{
    return implementation->commandController;
}
const QString& MasterController::welcomeMessage() const
{
    return implementation->welcomeMessage;
}

ScannedData *MasterController::recentlyScannedData()
{
    return implementation->recentlyScannedData;
}

DailyStatisticsData *MasterController::obtainedDailyStatisticsData()
{
    return implementation->obtainedDailyStatisticsData;
}

CameraDeviceUi *MasterController::cameraDeviceModel()
{
    return implementation->cameraDeviceModel;
}

ProfilometerDeviceUi *MasterController::profilometerDeviceModel()
{
    return implementation->profilometerDeviceModel;
}



}}
