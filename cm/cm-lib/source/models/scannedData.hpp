//
// Created by lukas on 12/5/2021.
//

#ifndef CONTROLLERS_SCANNEDDATA_HPP
#define CONTROLLERS_SCANNEDDATA_HPP
#include <cm-lib_global.h>
#include <QObject>
#include <QtCharts>


#include <data/entity.h>
#include <data/entity-collection.h>

#include <cstdint>
#include <utility>
#include <vector>
#include <QImage>
#include "../controllers/LowLevelFunctionality/Common/CustomEnumTypes.hpp"

namespace ac {
namespace models {

//using namespace QtCharts;

class CMLIB_EXPORT ScannedData : public cm::data::Entity {
    //ui
    Q_OBJECT
    Q_PROPERTY( int ui_out1   MEMBER out1   CONSTANT )
    Q_PROPERTY( int ui_out2   MEMBER out2   CONSTANT )
    Q_PROPERTY( int ui_out3   MEMBER out3   CONSTANT )
    Q_PROPERTY( int ui_outA   MEMBER outA   CONSTANT )
    Q_PROPERTY( QLineSeries* ui_profile READ get_ui_profile WRITE set_ui_profile NOTIFY profile_changed)

public:
    explicit ScannedData(QObject *parent = nullptr);

    ScannedData(QObject* parent, const QJsonObject& json);

    //profilometer
    uint16_t out1 {0};
    uint16_t out2 {0};
    uint16_t out3 {0};
    uint16_t outA {0};
    std::vector<std::pair<uint16_t,uint16_t>> profileData {};
    ScanResult resultProfilometer {ScanResult::Unrecognized};

    //camera
    QImage cameraImage {};
    ScanResult resultCamera {ScanResult::Unrecognized};


    //Overall Result
    ScanResult finalResult {ScanResult::Unrecognized};
    QLineSeries* get_ui_profile() const;
    void set_ui_profile(QLineSeries *series);
signals:
    void profile_changed();
private:
   QLineSeries* convertedProfile; //It's created in qml
};
}
}

#endif //CONTROLLERS_SCANNEDDATA_HPP
