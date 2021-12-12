#include "dailyStatisticsData.h"
#include "../controllers/LowLevelFunctionality/FileSystemController/FileSystem/FileSystemController.hpp"



namespace ac {
namespace models {
////INTEGRAL PARTS OF CLASS
DailyStatisticsData::DailyStatisticsData(QObject *parent) : Entity(parent, "ScannedData")
{
    name = static_cast<cm::data::StringDecorator*>(addDataItem(new cm::data::StringDecorator(this, "dailyStatisticData", "dataInfo")));
    /*
     *
     *
     *  IMPLEMENTATION - PARSING TO JSON
     *
     *
     */
}

DailyStatisticsData::DailyStatisticsData(QObject *parent, const QJsonObject &json): DailyStatisticsData(parent)
{
    update(json);
}

////CHART value

void DailyStatisticsData::onUpdateDailyStatistics()
{
    qDebug()<<"Updating DailyStatistics";
    updateDailyData();
}
void DailyStatisticsData::updateDailyData()
{
    healthyList.clear();
    unrecognizedList.clear();
    unhealthyList.clear();
    dates.clear();

    std::vector<std::tuple<std::string, int, int, int>> dailyData = {};
    dailyData = FileSystemController::GetInstance()->getDailyStatisticsFromLastNDays(6);
    for(auto& day: dailyData)
    {
        auto[date,healthy, unrecognized, unhealthy] = day;
        //update date format
        auto dateDelimiter = "-";
        date.insert(2,dateDelimiter);
        date.insert(5,dateDelimiter);
        //update lists
        dates.append(QString::fromStdString(date));
        healthyList.append(healthy);
        unhealthyList.append(unhealthy);
        unrecognizedList.append(unrecognized);

    }
    emit dailyStatisticsDataChanged();
}



}
}
