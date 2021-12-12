#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H



#include <QObject>
#include <QScopedPointer>
#include <QString>
#include <cm-lib_global.h>
#include <controllers/navigation-controller.h>
#include <controllers/command-controller.h>
#include <models/client.h>
#include <models/storage.h>
#include <models/scannedData.hpp>
#include <models/dailyStatisticsData.h>

namespace cm {
namespace controllers {

using Client = cm::models::Client;
using Storage = cm::models::Storage;
using ScannedData = ac::models::ScannedData;
using DailyStatisticsData = ac::models::DailyStatisticsData;

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString                                ui_welcomeMessage       READ welcomeMessage       CONSTANT )
//    we are adding here namespace info because it is access from ui side
    Q_PROPERTY( cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY( cm::controllers::CommandController*    ui_commandController    READ commandController    CONSTANT )
    Q_PROPERTY( cm::models::Client*                    ui_newClient            READ newClient            CONSTANT )
    Q_PROPERTY( cm::models::Storage*                   ui_basicStorage         READ basicStorage         CONSTANT )
    Q_PROPERTY( ac::models::ScannedData*               ui_scannedData          READ recentlyScannedData  CONSTANT )
    Q_PROPERTY( ac::models::DailyStatisticsData*       ui_dailyData            READ obtainedDailyStatisticsData  CONSTANT )




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
    const QString& welcomeMessage() const;
    Client *newClient();
    Storage *basicStorage();
    ScannedData *recentlyScannedData();
    DailyStatisticsData *obtainedDailyStatisticsData();
public slots:
    void onMeasureButtonClicked();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}}
#endif
