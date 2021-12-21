
#include "FileSystemController.hpp"
#include <QDir>
#include <QFile>
#include <sstream>

////INTEGRAL PARTS OF CLASS

FileSystemController* FileSystemController::GetInstance() {
    if (fsc_ == nullptr) {
        fsc_ = new FileSystemController();
    }
    return fsc_;
}

FileSystemController::FileSystemController(bool isLogInfoEnable, bool isLogErrorEnable) : SimpleLogger(isLogInfoEnable,
                                                                                                       isLogErrorEnable) {
    std::stringstream statisticHeadlineSS;
    statisticHeadlineSS << delimiter;
    statisticHeadlineSS << setw(initialPadding,"id") << delimiter;
    statisticHeadlineSS << setw(padding,"Healthy") << delimiter;
    statisticHeadlineSS << setw(padding,"Unrecognized") << delimiter;
    statisticHeadlineSS << setw(padding,"Unhealthy") << delimiter;
    statisticHeadlineSS << std::endl;
    statisticHeadline = statisticHeadlineSS.str();

    std::stringstream scanDataHeadlineSS;
    scanDataHeadlineSS << setw(initialPadding," ") << delimiter;
    scanDataHeadlineSS << setw(padding,"Result") << delimiter;
    scanDataHeadlineSS << setw(padding,"Out1setw") << delimiter;
    scanDataHeadlineSS << setw(padding,"Out2setw") << delimiter;
    scanDataHeadlineSS << setw(padding,"Out3setw") << delimiter;
    scanDataHeadlineSS << setw(padding,"OutAsetw") << delimiter;
    scanDataHeadlineSS << setw(padding,"XCoordsetw") << delimiter;
    scanDataHeadlineSS << setw(padding,"YCoordsetw") << delimiter;
    scanDataHeadline = scanDataHeadlineSS.str();

}

////BASIC CMD

int FileSystemController::addProfilometerScanDataToCategorizedDataBase(ScanResult result, int out1, int out2,
                                                                       int out3,
                                                                       int outA,
                                                                       const std::vector<std::pair<int,int>>& profileData, std::string commonTimeStamp) {
    //if commonTimeStamp exists, it uses it
    auto scanId = commonTimeStamp.empty() ? getFullTimeStamp() : commonTimeStamp;

    auto resultCategoryDirectoryPath = savePath + ac::translators::getResultName(result);
    auto directoryPath =  resultCategoryDirectoryPath + "/" + scanId ;
    auto fullPath = directoryPath + "/" + scanId + "_profilometer" + ".txt";

    //check
    QFile testfile(QString::fromStdString(fullPath));
    if (testfile.exists()) {
        LG_INF("FAILURE - FILE EXISTS - cmd addProfilometerScanDataToCategorizedDataBase");
        return -1;
    }

    //creating directories if needed
    if( not QDir().exists(QString::fromStdString(resultCategoryDirectoryPath))){
        QDir().mkdir(QString::fromStdString(resultCategoryDirectoryPath));
    }
    if( not QDir().exists(QString::fromStdString(directoryPath))){
        QDir().mkdir(QString::fromStdString(directoryPath));
    }

    //saving data to file
    std::ofstream file;
    file.open(fullPath);
    if (file.is_open()) {
        LG_INF("SUCCESS - FILE WAS OPENED CORRECTLY - cmd addProfilometerScanDataToCategorizedDataBase");
    } else {
        LG_ERR("FAILURE - FILE WAS NOT OPENED CORRECTLY " + std::string(strerror(errno)) + " - " + fullPath +
               " - " +
               "cmd addProfilometerScanDataToCategorizedDataBase");
        return -1;
    }


    file << warningScanData;
    file << scanDataHeadline << std::endl;
    file << delimiter << setw(initialPadding - 1,scanId) << delimiter;
    file << setw(padding,std::to_string(result)) << delimiter;
    file << setw(padding,std::to_string(out1)) << delimiter;
    file << setw(padding,std::to_string(out2)) << delimiter;
    file << setw(padding,std::to_string(out3)) << delimiter;
    file << setw(padding,std::to_string(outA)) << delimiter;

    //      for (auto pairXY : profileData) {
    for (auto it = profileData.begin(); it < profileData.end(); it++) {
        file << setw(padding,std::to_string(it->first)) << delimiter;
        file << setw(padding,std::to_string(it->second)) << delimiter;
        if (it + 1 != profileData.end()) {
            file << std::endl;
            // delimiter.size() to te 1
            file << setw(initialPadding + padding * 5 + 6 * 1,std::string{delimiter});
        }
    }
    file.close();
    return 0;
}

int FileSystemController::addCameraImageToCategorizedDataBase(ScanResult result, cv::Mat image, std::string commonTimeStamp) {

    if(image.empty()){
        LG_ERR("IMAGE RECEIVED IS EMPTY - FileSystemController::addCameraImageToCategorizedDataBase");
        return -1;
    }

    //if commonTimeStamp exists, it uses it
    auto scanId = commonTimeStamp.empty() ? getFullTimeStamp() : commonTimeStamp;

    auto resultCategoryDirectoryPath = savePath + ac::translators::getResultName(result);
    auto directoryPath =  resultCategoryDirectoryPath + "/" + scanId ;
    auto fullPath = directoryPath + "/" + scanId + "_camera" + ".jpg";

    //check
    QFile testfile(QString::fromStdString(fullPath));
    if (testfile.exists()) {
        LG_ERR("FAILURE - IMAGE EXISTS - cmd addCameraImageToCategorizedDataBase");
        return -1;
    }

    //creating directories if needed
    if( not QDir().exists(QString::fromStdString(resultCategoryDirectoryPath))){
        QDir().mkdir(QString::fromStdString(resultCategoryDirectoryPath));
    }
    if( not QDir().exists(QString::fromStdString(directoryPath))){
        QDir().mkdir(QString::fromStdString(directoryPath));
    }

    //saving image
    if (cv::imwrite(fullPath,image)) {
        LG_INF("SUCCESS - IMAGE WAS SAVED - cmd addCameraImageToCategorizedDataBase");
    } else {
        LG_ERR("FAILURE - IMAGE WAS NOT SAVED - " + std::string(strerror(errno)) + " - " + directoryPath +
               " - " +
               "cmd addCameraImageToCategorizedDataBase");
        return -1;
    }
    return 0;
}

int FileSystemController::addScanToDailyStatistic(ScanResult result) {

    auto stamp = getDailyTimeStamp();
    auto fullPath = savePath + dailyStatisticFileName;

    std::ofstream wFile;
    std::ifstream rFile;

    QFile testfile(QString::fromStdString(fullPath));
    if (not testfile.exists()) {
        LG_INF("CREATING DATA BASE - FILE DOES NOT EXIST - cmd addScanToDailyStatistic");
        wFile.open(fullPath);
        if (wFile.is_open()) {
            LG_INF("SUCCESS - FILE wFile WAS OPENED CORRECTLY - cmd addScanToDailyStatistic");
        } else {
            LG_ERR("FAILURE - FILE wFile WAS NOT OPENED CORRECTLY - " + std::string(strerror(errno)) + " - " +
                   fullPath + " - " +
                   "cmd addScanToDailyStatistic");
            return -1;
        }
        wFile << warningScanData;
        wFile << statisticHeadline;
        wFile << getNewDailyStatisticLine(stamp, result);
        wFile.close();
        return 1;
    }


    rFile.open(fullPath);
    if (rFile.is_open()) {
        LG_INF("SUCCESS - FILE rFile WAS OPENED CORRECTLY - cmd addScanToDailyStatistic");
    } else {
        LG_ERR("FAILURE - FILE rFile WAS NOT OPENED CORRECTLY - " + std::string(strerror(errno)) + " - " +
               fullPath + " - " +
               "cmd addScanToDailyStatistic");
        return -1;
    }

    std::stringstream reWrittenDailyStatistic;
    std::string line;

    int nrLine = 0;
    int nrDataLine = 0;
    nrDataLine += std::count(warningStatisticData.cbegin(), warningStatisticData.cend(), '\n');
    nrDataLine += std::count(statisticHeadline.cbegin(), statisticHeadline.cend(), '\n');
    nrDataLine += 1;

    while (getline(rFile, line)) {
        nrLine++;
        if (nrLine == nrDataLine) {
            std::pair<int, std::string> modifiedLine = getNewOrUpdatedDailyStatisticLine(line, stamp, result);
            switch (modifiedLine.first) {
            case (1): //ADD
                reWrittenDailyStatistic << modifiedLine.second;
                reWrittenDailyStatistic << std::endl;
                break;
            case (0): //UPDATE
                reWrittenDailyStatistic << modifiedLine.second;
                reWrittenDailyStatistic << std::endl;
                continue;
            case (-1): //ERROR OBVIOUSLY
                LG_ERR("FAILURE - DURING " + fullPath + " READING - addScanToHistoryDataBase");
                return -1;
            }
        }


        reWrittenDailyStatistic << line;
        reWrittenDailyStatistic << "\n"; // probably necessary
    }
    rFile.close();

    wFile.open(fullPath, std::ios::out | std::ios::trunc); //clears all previous content
    if (wFile.is_open()) {
        LG_INF("SUCCESS - FILE wFile WAS OPENED CORRECTLY - overwriting -cmd addScanToDailyStatistic");
    } else {
        LG_ERR("FAILURE - FILE wFile WAS NOT OPENED CORRECTLY - overwriting - " + std::string(strerror(errno)) +
               " - " +
               fullPath + " - " +
               "cmd addScanToDailyStatistic");
        return -1;
    }
    wFile << reWrittenDailyStatistic.str();

    return 0;
}

std::vector<std::tuple<std::string, int, int, int>> FileSystemController::getDailyStatisticsFromLastNDays(int n) {
    std::ifstream rFile;
    auto fullPath = savePath + dailyStatisticFileName;

    rFile.open(fullPath);
    if (rFile.is_open()) {
        LG_INF("SUCCESS - FILE rFile WAS OPENED CORRECTLY - cmd getDailyStatisticFromLastNDays");
    } else {
        LG_ERR("FAILURE - FILE rFile WAS NOT OPENED CORRECTLY - " + std::string(strerror(errno)) + " - " +
               fullPath + " - " +
               "cmd getDailyStatisticFromLastNDays");
        return {};
    }

    int nrLine = 0;
    int nrDataLine = 0;
    nrDataLine += std::count(warningStatisticData.cbegin(), warningStatisticData.cend(), '\n');
    nrDataLine += std::count(statisticHeadline.cbegin(), statisticHeadline.cend(), '\n');
    nrDataLine += 1;
    std::string line;
    std::vector<std::tuple<std::string, int, int, int>> dailyData;
    int nrFinalLineToRead = nrDataLine + n - 1;
    while (getline(rFile, line)) {
        nrLine++;
        if (nrFinalLineToRead >= nrLine && nrLine >= nrDataLine) {
            std::string date = getNStringBetween(0, delimiter, delimiter, line);
            int healthy = stoi(getNStringBetween(1, delimiter, delimiter, line));
            int unrecognized = stoi(getNStringBetween(2, delimiter, delimiter, line));
            int unhealthy = stoi(getNStringBetween(3, delimiter, delimiter, line));
            dailyData.emplace_back(date, healthy, unrecognized, unhealthy);
        } else if (nrLine > nrFinalLineToRead) {
            break;
        }
    }

    if (nrLine < nrFinalLineToRead) {
        LG_INF("FAILURE - " + std::to_string(nrFinalLineToRead - nrLine) +
               " LINE/LINES WHERE NOT READ - ENTRIES DO NOT EXIST - cmd getDailyStatisticFromLastNDays");
    }

    return dailyData;
}

////BASIC CMD INTERNAL HELPERS
std::pair<int, std::string>
FileSystemController::getNewOrUpdatedDailyStatisticLine(const std::string& line, const std::string& stamp,
                                                        const ScanResult& result) {
    std::string lineStamp = getNStringBetween(0, line[0], delimiter, line);

    //Inverse yyyy-mm-dd is easier to compare in context of stamp age

    std::string lineStampInverted = std::string{lineStamp}.substr(4) + std::string{lineStamp}.substr(2, 2) +
            std::string{lineStamp}.substr(0, 2);
    std::string measureStampInverted = std::string{stamp}.substr(4) + std::string{stamp}.substr(2, 2) +
            std::string{stamp}.substr(0, 2);
    if (stoi(measureStampInverted) > stoi(lineStampInverted)) {
        std::string newLine = getNewDailyStatisticLine(stamp, result);
        if (newLine.empty())
            return {-1, newLine};
        else {
            return {1, newLine};
        }
    } else if (lineStamp == stamp) {
        std::string updatedLine = updateDailyStatisticLine(line, stamp, result);
        if (updatedLine.empty())
            return {-1, updatedLine};
        else {
            return {0, updatedLine};
        }
    }

    LG_ERR("FAILURE - TOO EARLY DATE - YOU CAN'T MODIFY STATISTIC FROM PREVIOUS DAYS - cmd addOrUpdateStatisticLine ");
    return {-1, ""};

}

std::string FileSystemController::getNewDailyStatisticLine(const std::string& stamp, const ScanResult& result) {
    std::stringstream newStatisticLine;
    std::string healthyStr;
    std::string unrecognizedStr;
    std::string unhealthyStr;

    //        int lineStampDay = stoi(std::string{lineStamp}.substr(0, 2));
    //        int lineStampMonth = stoi(std::string{lineStamp}.substr(2, 4));
    //        int lineStampYear = stoi(std::string{lineStamp}.substr(4));
    //
    //        int measureStampDay = stoi(std::string{stamp}.substr(0, 2));
    //        int measureStampMonth = stoi(std::string{stamp}.substr(2, 4));
    //        int measureStampYear = stoi(std::string{stamp}.substr(4));


    switch (result) {
    case (ScanResult::Healthy):
        healthyStr = "1";
        unrecognizedStr = "0";
        unhealthyStr = "0";
        break;

    case (ScanResult::Unrecognized):
        healthyStr = "0";
        unrecognizedStr = "1";
        unhealthyStr = "0";
        break;

    case (ScanResult::Unhealthy):
        healthyStr = "0";
        unrecognizedStr = "0";
        unhealthyStr = "1";
        break;

    default:
        LG_ERR("FAILURE - UNRECOGNIZED RESULT - cmd getNewDailyStatisticLine");
        return "";
    }
    newStatisticLine << delimiter;
    newStatisticLine << setw(initialPadding,stamp) << delimiter;
    newStatisticLine << setw(padding,healthyStr) << delimiter;
    newStatisticLine << setw(padding,unrecognizedStr) << delimiter;
    newStatisticLine << setw(padding,unhealthyStr) << delimiter;
    auto str = newStatisticLine.str();
    return newStatisticLine.str();
}

std::string FileSystemController::updateDailyStatisticLine(const std::string& line, const std::string& stamp,
                                                           const ScanResult& result) {
    std::stringstream updatedStatisticLine;
    std::string healthyStr;
    std::string unrecognizedStr;
    std::string unhealthyStr;


    healthyStr = getNStringBetween(1, delimiter, delimiter, line);
    unrecognizedStr = getNStringBetween(2, delimiter, delimiter, line);
    unhealthyStr = getNStringBetween(3, delimiter, delimiter, line);

    switch (result) {
    case (ScanResult::Healthy):
        healthyStr = std::to_string(stoi(healthyStr) + 1);
        break;

    case (ScanResult::Unrecognized):
        unrecognizedStr = std::to_string(stoi(unrecognizedStr) + 1);
        break;

    case (ScanResult::Unhealthy):
        unhealthyStr = std::to_string(stoi(unhealthyStr) + 1);
        break;
    default:
        LG_ERR("FAILURE - UNRECOGNIZED RESULT - updateDailyStatisticLine");
        return "";
    }
    updatedStatisticLine << delimiter;
    updatedStatisticLine << setw(initialPadding,stamp) << delimiter;
    updatedStatisticLine << setw(padding,healthyStr) << delimiter;
    updatedStatisticLine << setw(padding,unrecognizedStr) << delimiter;
    updatedStatisticLine << setw(padding,unhealthyStr) << delimiter;
    return updatedStatisticLine.str();

}

////HELPERS

std::string FileSystemController::getFullTimeStamp() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;
    int second = ltm->tm_sec;
    std::string timeStamp;
    addToTimeStamp(timeStamp, hour);
    addToTimeStamp(timeStamp, minute);
    addToTimeStamp(timeStamp, second);
    timeStamp += "_";
    addToTimeStamp(timeStamp, day);
    addToTimeStamp(timeStamp, month);
    addToTimeStamp(timeStamp, year);
    return timeStamp;
}

std::string FileSystemController::getDailyTimeStamp() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    std::string timeStamp;
    addToTimeStamp(timeStamp, day);
    addToTimeStamp(timeStamp, month);
    addToTimeStamp(timeStamp, year);
    return timeStamp;
}

void FileSystemController::addToTimeStamp(std::string& timeStamp, int value) {
    //fills with zero in front if one digit number
    if (value < 10) {
        timeStamp += std::to_string(0);
    }
    timeStamp += std::to_string(value);
}

std::string FileSystemController::getNStringBetween(int n, char a, char b, std::string text) {
    //        auto it_begin = std::find_if(text.cbegin(), text.cend(), [](char c) { return not std::isdigit(c); }
    auto it_begin = std::find_if(text.cbegin(), text.cend(), [&a](char c) { return c == a; });
    auto it_end = std::find_if(it_begin + 1, text.cend(), [&b](char c) { return c == b; });

    if (n > 0 && it_begin != text.end() && it_end != text.end()) {
        return getNStringBetween(n - 1, a, b, std::string{it_end, text.cend()});
    }
    if (it_begin != text.end()) {
        std::string result = std::string{it_begin + 1, it_end};
        //cleaning
        result.erase(std::remove_if(result.begin(), result.end(), [](unsigned char x) { return std::isspace(x); }),
                     result.end());
        return result;

    } else {
        return "";
    }

}

std::string FileSystemController::setw(int designatedSize, std::string text)
{
    int sizeDiff = designatedSize - text.size();
    std::stringstream paddedString;
    if(sizeDiff > 0){
        for(int i = 0; i < sizeDiff; i++){
            paddedString << " ";
        }
    }
    paddedString <<text;
    return paddedString.str();

}

////VARIABLES

FileSystemController* FileSystemController::fsc_ = nullptr;


