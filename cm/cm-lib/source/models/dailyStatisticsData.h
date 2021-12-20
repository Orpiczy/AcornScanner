#ifndef DAILYSTATISTICSDATA_H
#define DAILYSTATISTICSDATA_H
#include <cm-lib_global.h>
#include <QObject>
#include <data/entity.h>
#include <data/entity-collection.h>
#include <data/string-decorator.h>

namespace ac {
namespace models {
class CMLIB_EXPORT DailyStatisticsData : public cm::data::Entity
{
    Q_OBJECT
    Q_PROPERTY(QList<int>     ui_healthy_list        MEMBER healthyList      NOTIFY dailyStatisticsDataChanged)
    Q_PROPERTY(QList<int>     ui_unhealthy_list      MEMBER unhealthyList    NOTIFY dailyStatisticsDataChanged)
    Q_PROPERTY(QList<int>     ui_unrecognized_list   MEMBER unrecognizedList NOTIFY dailyStatisticsDataChanged)
    Q_PROPERTY(QList<QString> ui_dates               MEMBER dates            NOTIFY dailyStatisticsDataChanged)

    Q_PROPERTY(int            ui_yAxisMax            MEMBER yAxisMax         NOTIFY dailyStatisticsDataChanged)
    Q_PROPERTY(int            ui_yAxisTickCount      MEMBER yAxisTickCount   NOTIFY dailyStatisticsDataChanged)

//    QList<int> healthyList = {2, 2, 3, 4, 5, 6};
//    QList<int> unhealthyList = {5, 1, 2, 4, 1, 7};
//    QList<int> unrecognizedList = {3, 5, 8, 13, 5, 8};
//    QList<QString> dates = {"29-11-2021", "28-11-2021", "27-11-2021", "26-11-2021", "25-11-2021", "24-11-2021" };

    QList<int> healthyList = {};
    QList<int> unhealthyList = {};
    QList<int> unrecognizedList = {};
    QList<QString> dates = {};

    int yAxisMax = 15;
    int yAxisTickCount = 6 ;

public:
    ////INTEGRAL PARTS OF CLASS
    explicit DailyStatisticsData(QObject *parent = nullptr);
    DailyStatisticsData(QObject* parent, const QJsonObject& json);
    cm::data::StringDecorator* name{nullptr};
    void updateDailyData();
public slots:
    void onUpdateDailyStatistics();
signals:
    void dailyStatisticsDataChanged();

private:
    const int yAxisResolution = 3;
};

}
}

#endif // DAILYSTATISTICSDATA_H
