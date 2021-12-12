//
// Created by lukas on 12/5/2021.
//

#ifndef CONTROLLERS_SCANNEDDATA_HPP
#define CONTROLLERS_SCANNEDDATA_HPP
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
    Q_PROPERTY( QString                    ui_filename READ get_ui_filename                     NOTIFY profile_changed)
    Q_PROPERTY( int                        ui_out1     MEMBER out1                                NOTIFY profile_changed)
    Q_PROPERTY( int                        ui_out2     MEMBER out2                                NOTIFY profile_changed)
    Q_PROPERTY( int                        ui_out3     MEMBER out3                                NOTIFY profile_changed)
    Q_PROPERTY( int                        ui_outA     MEMBER outA                                NOTIFY profile_changed)
    Q_PROPERTY( QString                    ui_result   READ get_ui_result                       NOTIFY profile_changed)
    Q_PROPERTY( QLineSeries*               ui_profile  READ   get_ui_profile WRITE set_ui_profile NOTIFY profile_changed)


    //profile chart's look
    Q_PROPERTY( int ui_xAxisMin        READ   get_ui_xAxisMin        NOTIFY axis_limit_changed)
    Q_PROPERTY( int ui_xAxisMax        READ   get_ui_xAxisMax        NOTIFY axis_limit_changed)
    Q_PROPERTY( int ui_xAxisTickCount  READ   get_ui_xAxisTickCount  NOTIFY axis_tick_count_changed)

    Q_PROPERTY( int ui_yAxisMin        READ   get_ui_yAxisMin        NOTIFY axis_limit_changed)
    Q_PROPERTY( int ui_yAxisMax        READ   get_ui_yAxisMax        NOTIFY axis_limit_changed)
    Q_PROPERTY( int ui_yAxisTickCount  READ   get_ui_yAxisTickCount  NOTIFY axis_tick_count_changed)
public:

    ////CONNECTIONS


    ////INTEGRAL PARTS OF CLASS
    explicit ScannedData(QObject *parent = nullptr);
    ScannedData(QObject* parent, const QJsonObject& json);
    cm::data::StringDecorator* name{nullptr};

    ////profilometer
    std::string fileName {};
    uint16_t out1 {0};
    uint16_t out2 {0};
    uint16_t out3 {0};
    uint16_t outA {0};
    std::vector<std::pair<uint16_t,uint16_t>> profileData {};
    ScanResult resultProfilometer {ScanResult::Unrecognized};

    ////camera
    QImage cameraImage {};
    ScanResult resultCamera {ScanResult::Unrecognized};


    ////Overall Result
    ScanResult finalResult {ScanResult::Healthy};

    ////CHART value
    QLineSeries* get_ui_profile() const;
    void set_ui_profile(QLineSeries *series);
    void update_ui_profile();

    QString get_ui_result();
    QString get_ui_filename();

    ////CHART look
    int get_ui_xAxisMin() {return 0;}
    int get_ui_xAxisMax() {return 0;}
    int get_ui_xAxisTickCount() {return 0;}

    int get_ui_yAxisMin() {return 0;}
    int get_ui_yAxisMax() {return 0;}
    int get_ui_yAxisTickCount() {return 0;}

    ////debugging
    void printProfile();
signals:
    void profile_changed();
    void axis_limit_changed();
    void axis_tick_count_changed();

private:
    QLineSeries* convertedProfile; //It's created in qml, we have only reference here
};
}
}

#endif //CONTROLLERS_SCANNEDDATA_HPP
