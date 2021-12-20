//
// Created by lukas on 12/3/2021.
//

#ifndef FILESYSTEM_FILESYSTEM_CONTROLLER_HPP
#define FILESYSTEM_FILESYSTEM_CONTROLLER_HPP
////OPENCV related
#include <opencv2/opencv.hpp>
////
#include <cm-lib_global.h>

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <vector>
#include <QImage>
#include "../../BaseClasses/SimpleLogger.hpp"
#include "../../Common/CustomEnumTypes.hpp"
#include "../../Common/Translators.hpp"


class CMLIB_EXPORT FileSystemController : private SimpleLogger {
    friend class DeviceController;
////METHODS
public:

    ////INTEGRAL PARTS OF CLASS
    static FileSystemController* GetInstance();

    FileSystemController(FileSystemController& other) = delete;

    void operator=(const FileSystemController&) = delete;

    ////BASIC CMD

    int addProfilometerScanDataToCategorizedDataBase(ScanResult result, uint16_t out1, uint16_t out2,
                                                     uint16_t out3, uint16_t outA,
                                                     const std::vector<std::pair<uint16_t, uint16_t>>& profileData, std::string commonTimeStamp = {});

    int addCameraImageToCategorizedDataBase(ScanResult result, cv::Mat image, std::string commonTimeStamp = {});

    int addScanToDailyStatistic(ScanResult result);

    std::vector<std::tuple<std::string, int, int, int>> getDailyStatisticsFromLastNDays(int n = 6);


protected:
    ////INTEGRAL PARTS OF CLASS
    explicit FileSystemController(bool isLogInfoEnable = false, bool isLogErrorEnable = false);

private:
    ////BASIC CMD INTERNAL HELPERS

    std::pair<int, std::string>
    getNewOrUpdatedDailyStatisticLine(const std::string& line, const std::string& stamp, const ScanResult& result);

    std::string
    getNewDailyStatisticLine(const std::string& stamp, const ScanResult& result);


    std::string
    updateDailyStatisticLine(const std::string& line, const std::string& stamp,
                             const ScanResult& result);


    ////HELPERS
    std::string getFullTimeStamp();

    void addToTimeStamp(std::string& timeStamp, int value);

    std::string getNStringBetween(int n, char a, char b, std::string text);

    std::string setw(int designatedSize,std::string text);




////VARIABLES

protected:
    static FileSystemController* fsc_;
private:
    const char delimiter = '|';
    std::string statisticHeadline;
    std::string scanDataHeadline;

    const std::string savePath = "E:/Dokumenty/AiR_rok_4/S7/EngineeringThesis/AcornScanner/cm/cm-lib/source/controllers/LowLevelFunctionality/FileSystemController/Database/";
    const std::string warningScanData = "\n\n///// WARNING THIS IS READONLY MEASURE DATA /////\n\n\n";
    const std::string warningStatisticData = "\n\n///// WARNING THIS IS READONLY STATISTIC DATA /////\n\n\n";
    const std::string dailyStatisticFileName = "DailyStatistic.txt";
    const static char initCharForMainStamp = '_';
    const static char endCharForMainStamp = '.';
    const int padding = 12;
    const int initialPadding = 16;

    std::string getDailyTimeStamp();
};

#endif //FILESYSTEM_FILESYSTEM_CONTROLLER_HPP
