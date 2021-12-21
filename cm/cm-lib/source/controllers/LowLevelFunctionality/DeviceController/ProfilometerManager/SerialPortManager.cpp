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
    readBuffer_.reserve(readBufferSize_);
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
    LG_DBG("INFO - SENDING MESSAGE - SerialPortManager::sendMessage");
    //preparation
    if (not serialPort_.has_value()) {
        LG_INF("WARNING - PORT IS NOT SET UP - REATTEMPTING - SerialPortManager::sendMessage");
        setUpPort();
    }
    if (not serialPort_.has_value()) {
        LG_ERR("FAILURE - REATTEMPTING TO SET UP PORT ENDED IN FAILURE - SerialPortManager::sendMessage");
        return -1;
    }

    if(serialPort_.value()->isOpen() && serialPort_.value()->isWritable()){

        int bytesWritten = serialPort_.value()->write(&getCharVector(cmd)[0], cmd.size());
        serialPort_.value()->waitForBytesWritten(-1);

        LG_DBG("SUCCESS - MESSAGE WAS SENT - SerialPortManager::sendMessage");
        return bytesWritten;
    }

    LG_ERR("FAILURE - MESSAGE COULDN'T BE SENT - PORT IS NOT OPEN OR WRITABLE - SerialPortManager::sendMessage");
    return 0;
}

std::vector<uint8_t> SerialPortManager::readMessage() {
    LG_DBG("INFO - READING MESSAGE - SerialPortManager::readMessage()");
    //preparation
    if (not serialPort_.has_value()) {
        LG_INF("WARNING - PORT IS NOT SET UP - REATTEMPTING - SerialPortManager::readMessage()");
        setUpPort();
    }
    if (not serialPort_.has_value()) {
        LG_ERR("FAILURE - REATTEMPTING TO SET UP PORT ENDED IN FAILURE - SerialPortManager::readMessage()");
        return {};
    }

    std::fill(readBuffer_.begin(), readBuffer_.end(), 0);

    ssize_t n = -1;
    //reading
    if(serialPort_.value()->isReadable() && serialPort_.value()->waitForReadyRead()){
        n  = serialPort_.value()->read(&readBuffer_[0],readBufferSize_);
        LG_DBG("INFO - DEVICE IS READABLE - SerialPortManager::readMessage() - n bytes read = ", n );
    }else{
        LG_ERR("FAILUE - DEVICE IS NOT READABLE - SerialPortManager::readMessage()");
    }
    if(n > 0){
        LG_DBG("SUCCESS - MESSAGE WAS RECEIVED - SerialPortManager::readMessage()");
        return {readBuffer_.begin(), readBuffer_.begin() + n};
    }

    LG_ERR("FAILURE - MESSAGE WAS NOT READ/RECEIVED OR ERROR OCCURED - SerialPortManager::readMessage()");
    return {};
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
        n += serialPort_.value()->read(&readBuffer_[n], readBufferSize_ - n);
        i++;
        endSign = readBuffer_[abs(n - 2)];
    } while (endSign != 0x03 and i < maxConsecutiveReadCmd and n < readBufferSize_ and serialPort_.value()->waitForReadyRead(waitTimeForReadBufferToFill));
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















