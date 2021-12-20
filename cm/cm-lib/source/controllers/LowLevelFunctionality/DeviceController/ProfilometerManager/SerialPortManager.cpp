//
// Created by lukas on 06/11/2021.
//

#include <iostream>
#include "SerialPortManager.hpp"

////INTEGRAL PARTS OF CLASS
SerialPortManager::SerialPortManager(QString comPortName, bool isLogInfoEnable, bool isLogErrorEnable, QSerialPort::BaudRate defaultBaudRate)
      : SimpleLogger(isLogInfoEnable, isLogErrorEnable), defaultBaudRate_(defaultBaudRate),comPortName_(comPortName), serialPort_(std::nullopt)
{
    if (IS_PROFILOMETER_AVAILABLE) {
        //Settings
        setUpPort();
    }
    //BUFFER
    readBufferSize_ = defaultReadBufferSize_;
    readBuffer_.resize(readBufferSize_);
    std::fill(readBuffer_.begin(), readBuffer_.end(), 0);
}

SerialPortManager::~SerialPortManager() {
    closePort();
}

void SerialPortManager::closePort(){
    if(serialPort_.value()->isOpen()) {
      serialPort_.value()->close();
    }
}

//// MAIN FUNCTIONALITY
int SerialPortManager::sendMessage(const std::vector<uint8_t>& cmd) {
    //preparation
    if (not serialPort_.has_value()) {
        setUpPort();
    }
    if (not serialPort_.has_value()) {
        return -1;
    }
    return serialPort_.value()->write(&getCharVector(cmd)[0], cmd.size());

}

std::vector<uint8_t> SerialPortManager::readMessage() {
    //preparation
    if (not serialPort_.has_value()) {
        setUpPort();
    }
    if (not serialPort_.has_value()) {
        return {};
    }
    std::fill(readBuffer_.begin(), readBuffer_.end(), 0);


    //reading
    ssize_t n = serialPort_.value()->readData(&readBuffer_[0],readBufferSize_);
    return {readBuffer_.begin(), readBuffer_.begin() + n};
}

std::vector<uint8_t> SerialPortManager::readMessagesUntilEndSign() {
    //preparation
    if (not serialPort_.has_value()) {
        setUpPort();
    }
    if (not serialPort_.has_value()) {
        return {};
    }
    std::fill(readBuffer_.begin(), readBuffer_.end(), 0);

    //reading
    ssize_t n{0};
    int i = 0;
    uint8_t endSign{0};
    do {
        n += serialPort_.value()->readData(&readBuffer_[n], readBufferSize_ - n);
        i++;
        endSign = readBuffer_[abs(n - 2)];
    } while (endSign != 0x03 and i < maxConsecutiveReadCmd and n < readBufferSize_);
    return {readBuffer_.begin(), readBuffer_.begin() + n};
};

////HELPER
int SerialPortManager::setUpPort() {

    LG_DBG("INFO - ENTERING FUNCTION - SerialPortManager::setUpPort()");

    //PORT
    serialPort_ = new QSerialPort(this);
    serialPort_.value()->setPortName(comPortName_);

    //Open port, set values and check for errors
    if (serialPort_.value()->open(QSerialPort::ReadWrite)) {

        LG_DBG("SUCCESS - SETTING SERIAL PORT - SerialPortManager::setUpPort()");

        serialPort_.value()->setBaudRate(defaultBaudRate_);
        serialPort_.value()->setDataBits(QSerialPort::Data8);
        serialPort_.value()->setParity(QSerialPort::NoParity);
        serialPort_.value()->setStopBits(QSerialPort::OneStop);
        serialPort_.value()->setFlowControl(QSerialPort::NoFlowControl);

    }else{

        LG_ERR("FAILUE - SETTING SERIAL PORT FAILED- SerialPortManager::setUpPort()");

        serialPort_ = std::nullopt;
        return -1;
    }

    return 0;
}

void SerialPortManager::clearBuffer(uint8_t timeBeforeFlush) {

    LG_DBG("INFO - SETTING SERIAL PORT - SerialPortManager::setUpPort()");

    if (timeBeforeFlush > 0) {
        sleep(timeBeforeFlush);
    }
    serialPort_.value()->clear();
}

std::vector<char> SerialPortManager::getCharVector(const std::vector<uint8_t>& cmd){
    std::vector<char> result = {};
    for(auto el : cmd){
        result.push_back(el);
    }
    return result;
}















