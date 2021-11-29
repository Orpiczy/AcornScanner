#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QtQml/QQmlListProperty>

#include <cm-lib_global.h>
#include <data/string-decorator.h>
#include <data/map-decorator.h>
#include <data/entity.h>
#include <data/entity-collection.h>
#include <models/address.h>
#include <models/appointment.h>
#include <models/contact.h>
namespace cm {
namespace models {
//TO DO  set and get coffee sa nieuzywane, usun
class CMLIB_EXPORT Storage : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY( cm::data::StringDecorator* ui_name   MEMBER name   CONSTANT )
    Q_PROPERTY( cm::data::MapDecorator* ui_coffee MEMBER coffee CONSTANT)
    Q_PROPERTY( cm::data::MapDecorator* ui_change MEMBER change CONSTANT)
    Q_PROPERTY( cm::data::MapDecorator* ui_milk MEMBER milk CONSTANT)
    Q_PROPERTY( cm::data::MapDecorator* ui_water MEMBER water CONSTANT)
    Q_PROPERTY( cm::data::MapDecorator* ui_status MEMBER status CONSTANT)
    Q_PROPERTY( cm::data::MapDecorator* ui_users MEMBER users CONSTANT)
    Q_PROPERTY( cm::data::MapDecorator* ui_users_privileges MEMBER usersPrivileges CONSTANT)
    Q_PROPERTY( int ui_max_water MEMBER maxWater CONSTANT)
    Q_PROPERTY( int ui_max_milk MEMBER maxMilk CONSTANT)


public:
    explicit Storage(QObject *parent = nullptr);

     Storage(QObject* parent, const QJsonObject& json);

    data::StringDecorator* name{nullptr};
    data::MapDecorator*    coffee{nullptr};
    data::MapDecorator*    change{nullptr};
    data::MapDecorator*    milk{nullptr};
    data::MapDecorator*    water{nullptr};
    data::MapDecorator*    status{nullptr};
    data::MapDecorator*    users{nullptr};
    data::MapDecorator*    usersPrivileges{nullptr};

    int  getCoffee(QString coffeeName = "");
    void setCoffee(QString coffeeName = "",int amount = 0);

signals:
    void coffeeChanged();
public:
    static const int maxCoffee = 1000;
    static const int maxChange = 20;
    static const int maxMilk = 10;
    static const int maxWater = 50;

private:
    QMap<QString,int> getPopulatedCoffeeStorage();
    QMap<QString,int> getPopulatedChangeStorage();
    QMap<QString,int> getPopulatedMilkStorage();
    QMap<QString,int> getPopulatedWaterStorage();
    QMap<QString,int> getPopulatedStatusStorage();
    QMap<QString,int> getPopulatedUserStorage();
    QMap<QString,int> getPopulatedUserPrivilegesStorage();



};

}}
#endif // STORAGE_H
