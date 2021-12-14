#ifndef PROFILOMETERDEVICEUI_H
#define PROFILOMETERDEVICEUI_H

#include <QObject>
#include <QDebug>
#include "../controllers/LowLevelFunctionality/Common/CustomEnumTypes.hpp"
#include "../controllers/LowLevelFunctionality/Common/Translators.hpp"
class ProfilometerDeviceUi : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_device_id MEMBER deviceId CONSTANT)
    Q_PROPERTY(QString ui_connection_status MEMBER connectionStatus NOTIFY device_status_change)
    Q_PROPERTY(QString ui_functional_status MEMBER functionalStatus NOTIFY device_status_change)
public:
    explicit ProfilometerDeviceUi(QObject *parent = nullptr);

    ////VARIABLES
   QString deviceId {"Profilometer"};
   QString connectionStatus {"No"};
   QString functionalStatus {"DeviceNotFound"};

   signals:
   void device_status_change();

   public slots:
   void updateStatus();

};

#endif // PROFILOMETERDEVICEUI_H
