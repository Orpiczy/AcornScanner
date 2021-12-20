//
// Created by lukas on 06/11/2021.
//

#ifndef UNTITLED_PROFILOMETERMANAGER_HPP
#define UNTITLED_PROFILOMETERMANAGER_HPP
#include <cm-lib_global.h>

#include <iostream>
#include "SerialPortManager.hpp"
#include "MsgManager.hpp"
#include "../../BaseClasses/SimpleLogger.hpp"
#include "../../Common/CustomEnumTypes.hpp"
#include "../../Common/ControllersFlags.hpp"
#include "../../BaseClasses/DeviceManager.hpp"
#include "../../FileSystemController/FileSystem/FileSystemController.hpp"
#include "../../../../models/scannedData.hpp"

class CMLIB_EXPORT ProfilometerManager : public SerialPortManager, public DeviceManager {

public:

    ////INTEGRAL PARTS OF CLASS
    static ProfilometerManager*
    GetInstance();

    ProfilometerManager(ProfilometerManager& other) = delete; //can not be cloneable
    void operator=(const ProfilometerManager&) = delete; // can not be assignable

    ////BASIC CMD
    int addInfoToScannedData(ac::models::ScannedData& data) override {

        //TO DO - REFACTOR - ZALEZNOSC OD MAKRA IS_PROFILOMETER_AVAILABLE NIE POWINNA ISC TAK NISKO -> WCHODZI DO FUNKCJI

        if(IS_PROFILOMETER_AVAILABLE){

            data.out1 = getOut1();
            data.out2 = getOut2();
            data.out3 = getOut3();
            data.outA = getOutA();
            data.profileData = getProfile();

        }else{

            data.out1 = testOut1;
            data.out2 = testOut2;
            data.out3 = testOut3;
            data.outA = testOutA;
            data.profileData = testProfileData;

        }


        if(IS_PROFILOMETER_RESULT_CHECK_ENABLED){

            /*
             *
             *
             *  IMPLEMENTATION
             *
             *
             */

        }else{
            data.resultProfilometer = PROFILOMETER_RESULT;
        }

        return 0;
    }

    int addInfoToScannedDataAndSaveItToDataBase(ac::models::ScannedData& data, std::string commonTimeStamp = {}) override {

        //TO DO - REFACTOR - ZALEZNOSC OD MAKRA IS_PROFILOMETER_AVAILABLE NIE POWINNA ISC TAK NISKO -> WCHODZI DO FUNKCJI

        if(IS_PROFILOMETER_AVAILABLE){

            data.out1 = getOut1();
            data.out2 = getOut2();
            data.out3 = getOut3();
            data.outA = getOutA();
            data.profileData = getProfile();

        }else{

            data.out1 = testOut1;
            data.out2 = testOut2;
            data.out3 = testOut3;
            data.outA = testOutA;
            data.profileData = testProfileData;

        }


        if(IS_PROFILOMETER_RESULT_CHECK_ENABLED){

            /*
             *
             *
             *  IMPLEMENTATION
             *
             *
             */

        }else{
            data.resultProfilometer = PROFILOMETER_RESULT;
        }
        FileSystemController::GetInstance()->addProfilometerScanDataToCategorizedDataBase(data.resultProfilometer,
                                                                                          data.out1, data.out2,
                                                                                          data.out3, data.outA,
                                                                                          data.profileData,
                                                                                          commonTimeStamp);
        return 0;

    }




    ////HELPERS
    bool isConnectedAndWorking();

    ////CONTROLLER CONNECTION
    int checkFunctionalityAndUpdateStatus() override {return 0;}
protected:
    explicit ProfilometerManager(bool isLogInfoEnable = true, bool isLogErrorEnable = true, const QString comPortName = "COM9")
        : SerialPortManager(comPortName, isLogInfoEnable, isLogErrorEnable)  {}

    ////CMD
    int getOut1();

    int getOut2();

    int getOut3();

    int getOutA();


    ////PROFILE CMD
    std::vector<std::pair<uint16_t, uint16_t>> getProfile(int attemptNumber = 0);

    std::optional<uint32_t> getProfileDataAddress(int attemptNumber = 0);

    std::optional<std::tuple<uint16_t, float>> getProfileSizeTimeInfo(uint32_t memoryAddress, int attemptNumber = 0);

    std::optional<std::tuple<uint16_t, float, uint32_t>> getProfileSizeTimeInfoAndAddress(int attemptNumber = 0);

    std::optional<std::vector<uint8_t>> getValueFromMemoryAddress(uint32_t memoryAddress, int attemptNumber = 0);

    std::optional<std::vector<uint8_t>>
    getRequestedSizeValueFromMemoryAddress(uint32_t memoryAddress, size_t requestedDataLength, int attemptNumber = 0);

    static ProfilometerManager* pfm_;
private:
    int getOut(const std::vector<uint8_t>& cmd, const std::string& sourceName, int attemptNumber = 0);

    ///// TEST DATA, CAN BE DELETED IN PRODUCTION CODE
    const static std::vector<std::pair<uint16_t, uint16_t>> testProfileData;
    const static uint16_t testOut1 = 4123;
    const static uint16_t testOut2 = 235;
    const static uint16_t testOut3 = -2314;
    const static uint16_t testOutA = -13;
    const static ScanResult testResult = ScanResult::Unrecognized;
    int maxReAttempts = 2;
    int maxReadMemoryReAttempts = 5;

};


#endif //UNTITLED_PROFILOMETERMANAGER_HPP
