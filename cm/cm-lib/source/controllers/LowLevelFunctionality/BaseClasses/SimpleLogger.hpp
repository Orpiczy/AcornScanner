//
// Created by lukas on 14/11/2021.
//

#ifndef PROFILOMETERLINUX_SIMPLELOGGER_HPP
#define PROFILOMETERLINUX_SIMPLELOGGER_HPP

#include <string>

class SimpleLogger {


protected:
    explicit SimpleLogger(bool isLogInfoEnable, bool isLogErrorEnable, bool isLogDebugEnable = false)
            : isLogInfoEnable(isLogInfoEnable), isLogErrorEnable(isLogErrorEnable), isLogDebugEnable(isLogDebugEnable){}



    void LG_INF(const std::string& info) const;
    void LG_INF(const std::string& info, const int& intInfo) const;

    void LG_ERR(const std::string& info) const;
    void LG_ERR(const std::string& info, const int& intInfo) const;

    void LG_DBG(const std::string& info) const;
    void LG_DBG(const std::string& info, const int& intInfo) const;



    const bool isLogInfoEnable;
    const bool isLogErrorEnable;
    const bool isLogDebugEnable;

private:

    const std::string infoString  = " >> INFO  - ";
    const std::string errorString = " >> ERROR - ";
    const std::string debugString = " >> DEBUG - ";

};

#endif //PROFILOMETERLINUX_SIMPLELOGGER_HPP
