#ifndef MAPDECORATOR_H
#define MAPDECORATOR_H

#include <QObject>
#include <QMap>
#include <cm-lib_global.h>
#include <data/data-decorator.h>

namespace cm {
namespace data {

class CMLIB_EXPORT MapDecorator : public DataDecorator
{
    Q_OBJECT

    //    Q_PROPERTY( QMap<QString,int> ui_value MEMBER value)

    //UGLY AS FUCK -> YOU DONT KNOW HOW TO EXPOSE QMAP TO QML LAYER, OR EVEN PASS ARG TO READ FUNCTION
    Q_PROPERTY( int     ui_value0  READ valueFromInd0  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key0    READ keyFromInd0    NOTIFY valueRead )
    Q_PROPERTY( int     ui_value1  READ valueFromInd1  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key1    READ keyFromInd1   NOTIFY valueRead )
    Q_PROPERTY( int     ui_value2  READ valueFromInd2  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key2    READ keyFromInd2    NOTIFY valueRead )
    Q_PROPERTY( int     ui_value3  READ valueFromInd3  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key3    READ keyFromInd3    NOTIFY valueRead )
    Q_PROPERTY( int     ui_value4  READ valueFromInd4  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key4    READ keyFromInd4    NOTIFY valueRead )
    Q_PROPERTY( int     ui_value5  READ valueFromInd5  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key5    READ keyFromInd5    NOTIFY valueRead )
    Q_PROPERTY( int     ui_value6  READ valueFromInd6  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key6    READ keyFromInd6    NOTIFY valueRead )
    Q_PROPERTY( int     ui_value7  READ valueFromInd6  NOTIFY valueChanged)
    Q_PROPERTY( QString ui_key7    READ keyFromInd6    NOTIFY valueRead )

public:
    MapDecorator(Entity* parentEntity = nullptr, const QString& key = "SomeItemKey", const QString& label = "", QMap<QString,int> value  = QMap<QString,int>());
    ~MapDecorator();

    MapDecorator& setValue(QMap<QString,int>  value);
    MapDecorator& setValueOnKey(QString key,int value);

    QMap<QString,int> value() const;
    int valueFromKey(QString key) const;

    //NECESSARY GARBAGE -> YOU DONT KNOW HOW TO EXPOSE QMAP TO QML LAYER
    QPair<QString,int> pairFromInd(int index) const;
    int valueFromInd(int index = 0) const;
    QString keyFromInd(int index = 0) const;

    int valueFromInd0() const{
        return pairFromInd(0).second;
    }
    QString keyFromInd0() const{
        return pairFromInd(0).first;
    }
    int valueFromInd1() const{
        return pairFromInd(1).second;
    }
    QString keyFromInd1() const{
        return pairFromInd(1).first;
    }
    int valueFromInd2() const{
        return pairFromInd(2).second;
    }
    QString keyFromInd2() const{
        return pairFromInd(2).first;
    }
    int valueFromInd3() const{
        return pairFromInd(3).second;
    }
    QString keyFromInd3() const{
        return pairFromInd(3).first;
    }
    int valueFromInd4() const{
        return pairFromInd(4).second;
    }
    QString keyFromInd4() const{
        return pairFromInd(4).first;
    }
    int valueFromInd5() const{
        return pairFromInd(5).second;
    }
    QString keyFromInd5() const{
        return pairFromInd(5).first;
    }
    int valueFromInd6() const{
        return pairFromInd(6).second;
    }
    QString keyFromInd6() const{
        return pairFromInd(6).first;
    }
    int valueFromInd7() const{
        return pairFromInd(7).second;
    }
    QString keyFromInd7() const{
        return pairFromInd(7).first;
    }
    ///////////////

public:
    QJsonValue jsonValue() const override;
    void update(const QJsonObject& jsonObject) override;


signals:
    void valueChanged(QString key);
    void valueRead(QString key);

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}

#endif // MAPDECORATOR_H
