#include "dailyStatisticsData.h"
#include "../controllers/LowLevelFunctionality/FileSystemController/FileSystem/FileSystemController.hpp"
#include <QtMath>


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
    qDebug()<<"INFO - Updating DailyStatistics - DailyStatisticsData::onUpdateDailyStatistics()";
    updateDailyData();
}
void DailyStatisticsData::updateDailyData()
{
    //values
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

    //axis - looking for maximum
    int healthyMax = *std::max_element(healthyList.begin(),healthyList.end());
    int unhealthyMax = *std::max_element(unhealthyList.begin(),unhealthyList.end());
    int unrecognizedMax = *std::max_element(unrecognizedList.begin(),unrecognizedList.end());

    //updating
    int maxInAllCategories = std::max({healthyMax,unrecognizedMax,unhealthyMax});
    yAxisTickCount = (int) maxInAllCategories / yAxisResolution + 1;
    qDebug()<<"TickCount = "<<yAxisTickCount;
    yAxisMax = yAxisTickCount*yAxisResolution;
    qDebug()<<"yAxisMax"<< yAxisMax;
    yAxisTickCount += 1; //because 0 bar counts as a tick as well

    emit dailyStatisticsDataChanged();
}



}
}
