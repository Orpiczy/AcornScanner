#include "map-decorator.h"

#include <QVariant>

namespace cm {
namespace data {

class MapDecorator::Implementation
{
public:
    Implementation(MapDecorator* mapDecorator, QMap<QString,int> value)
        : mapDecorator(mapDecorator), value(value)
    {
    }
    MapDecorator* mapDecorator{nullptr};
    QMap<QString,int> value;
};

MapDecorator::MapDecorator(Entity* parentEntity, const QString& key, const QString& label, QMap<QString,int> value)
    : DataDecorator(parentEntity, key, label)
{
    implementation.reset(new Implementation(this, value));
}

MapDecorator::~MapDecorator()
{
}


QMap<QString, int> MapDecorator::value() const
{
    return implementation->value;
}

int MapDecorator::valueFromKey(QString key) const
{
    QMap<QString,int> map = implementation->value;
    auto it = map.find(key);
    if(it == map.end()){
        return 0;
    }else{
        return it.value();
    }
}


QPair<QString,int> MapDecorator::pairFromInd(int index) const{
    QMap<QString,int> map = implementation->value;
    auto it = map.begin();

    if(index < map.size()){
        std::advance(it,index);

    }
    return {it.key(),it.value()};
}
int MapDecorator::valueFromInd(int index) const
{
    return pairFromInd(index).second;
}

QString MapDecorator::keyFromInd(int index) const
{
    return pairFromInd(index).first;
}

MapDecorator &MapDecorator::setValue(QMap<QString, int> value)
{
    if(value != implementation->value) {
        // ...Validation here if required...
        implementation->value = value;
        emit valueChanged("all");
    }

    return *this;
}

MapDecorator& MapDecorator::setValueOnKey(QString key,int value)
{
    QMap<QString,int> map = implementation->value;
    auto it = map.find(key);
    if(it != map.end()){
        it.value() = value;
        emit valueChanged(key);
    }
    return *this;
}

QJsonValue MapDecorator::jsonValue() const
{
    QVariantMap vMap = {};
    QMap<QString,int> myMap(implementation->value);

    QMapIterator<QString, int> i(myMap);
    if(not myMap.empty()){
        vMap.insert(i.key(), i.value());
    }

    while (i.hasNext()) {
        i.next();
        vMap.insert(i.key(), i.value());
    }
    return QJsonValue::fromVariant(QVariant(vMap));
}

void MapDecorator::update(const QJsonObject& jsonObject)
{
    if (jsonObject.contains(key())) {
        QMap<QString, QVariant> mapFromJson = jsonObject.value(key()).toVariant().toMap();
        QMap<QString,int> myMap = {};

        QMapIterator<QString, QVariant> i(mapFromJson);
        if(not mapFromJson.empty()){
            myMap.insert(i.key(), i.value().toInt());
        }

        while (i.hasNext()) {
            i.next();
            myMap.insert(i.key(), i.value().toInt());
        }
        setValue(myMap);

    } else {

        setValue({});
    }
}

}}
