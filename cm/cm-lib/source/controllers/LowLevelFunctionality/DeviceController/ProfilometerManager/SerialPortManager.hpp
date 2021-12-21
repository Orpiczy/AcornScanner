//
// Created by lukas on 06/11/2021.
//

#ifndef UNTITLED_SERIALPORTMANAGER_HPP
#define UNTITLED_SERIALPORTMANAGER_HPP

#include <memory>
#include <optional>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <QSerialPortInfo>
#include <QSerialPort>
#include <unistd.h> // write(), read(), close()
#include <vector>
#include <stdio.h>
#include <string.h>
#include <QObject>
#include "../../Common/ControllersFlags.hpp"
#include "../../BaseClasses/SimpleLogger.hpp"


class SerialPortManager: public QObject, public SimpleLogger{
    Q_OBJECT
public:
    ////INTEGRAL PARTS OF CLASS
    SerialPortManager(QString comPortName = "COM9", bool isLogInfoEnable = false, bool isLogErrorEnable = true, QSerialPort::BaudRate defaultBaudRate = QSerialPort::Baud19200);

    SerialPortManager(SerialPortManager const&) = delete;

    SerialPortManager& operator=(SerialPortManager const&) = delete;

    virtual ~SerialPortManager();

    ////MAIN FUNCTIONALITY
    int sendMessage(const std::vector<uint8_t>& cmd);

    std::vector<uint8_t> readMessage();

    std::vector<uint8_t> readMessagesUntilEndSign();

    void closePort();

    void clearBuffer(uint8_t timeBeforeFlush = 0);


protected:
    int waitTimeForReadBufferToFill = 5000; //ms
    int readBufferSize_;
    int defaultReadBufferSize_ = 2048;
    int defaultBaudRate_;
    //    static constexpr auto defaultBaudRate_ = B57600;
    const int maxConsecutiveReadCmd = 30;
    QString comPortName_;
    std::optional<QSerialPort*> serialPort_;
    std::vector<char> readBuffer_;

    ////HELPERS
    int setUpPort();
    std::vector<char> getCharVector(const std::vector<uint8_t> &cmd);

};


#endif //UNTITLED_SERIALPORTMANAGER_HPP
