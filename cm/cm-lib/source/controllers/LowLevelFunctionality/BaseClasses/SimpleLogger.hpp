//
// Created by lukas on 14/11/2021.
//

#ifndef PROFILOMETERLINUX_SIMPLELOGGER_HPP
#define PROFILOMETERLINUX_SIMPLELOGGER_HPP

#include <string>

class SimpleLogger {
private:

    bool isLogInfoEnable_;
    bool isLogErrorEnable_;
    bool isLogDebugEnable_;


    const std::string infoString  = " >> INFO  - ";
    const std::string errorString = " >> ERROR - ";
    const std::string debugString = " >> DEBUG - ";

protected:
    explicit SimpleLogger(bool isLogInfoEnable, bool isLogErrorEnable, bool isLogDebugEnable = false)
            : isLogInfoEnable_(isLogInfoEnable), isLogErrorEnable_(isLogErrorEnable), isLogDebugEnable_(isLogDebugEnable){}



    void LG_INF(const std::string& info) const;
    void LG_INF(const std::string& info, const int& intInfo) const;

    void LG_ERR(const std::string& info) const;
    void LG_ERR(const std::string& info, const int& intInfo) const;

    void LG_DBG(const std::string& info) const;
    void LG_DBG(const std::string& info, const int& intInfo) const;


};

#endif //PROFILOMETERLINUX_SIMPLELOGGER_HPP
