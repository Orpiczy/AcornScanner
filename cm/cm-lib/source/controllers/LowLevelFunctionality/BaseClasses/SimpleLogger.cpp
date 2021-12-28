
#include <iostream>
#include "SimpleLogger.hpp"


void SimpleLogger::LG_INF(const std::string& info) const {
    if(isLogInfoEnable){
        std::cout<<infoString<<info<<std::endl;
    }
}

void SimpleLogger::LG_INF(const std::string& info, const int& intInfo) const {
    if(isLogInfoEnable){
        std::cout<<infoString<<info<<intInfo<<std::endl;
    }
}

void SimpleLogger::LG_ERR(const std::string& info) const {
    if(isLogErrorEnable and not info.empty()){
        std::cout<<errorString<<info<<std::endl;
    }
}

void SimpleLogger::LG_ERR(const std::string& info, const int& intInfo) const {
    if(isLogErrorEnable and not info.empty()){
        std::cout<<errorString<<info<<intInfo<<std::endl;
    }
}

void SimpleLogger::LG_DBG(const std::string& info) const {
    if(isLogDebugEnable and not info.empty()){
        std::cout<<debugString<<info<<std::endl;
    }
}

void SimpleLogger::LG_DBG(const std::string& info, const int& intInfo) const {
    if(isLogDebugEnable and not info.empty()){
        std::cout<<debugString<<info<<intInfo<<std::endl;
    }
}
