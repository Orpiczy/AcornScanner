//
// Created by lukas on 12/5/2021.
//

#ifndef CONTROLLERS_DEVICEMANAGER_HPP
#define CONTROLLERS_DEVICEMANAGER_HPP

#include "../Common/CustomEnumTypes.hpp"
#include "../../../models/scannedData.hpp"

class DeviceManager{
public:

    virtual int addInfoToScannedData(ac::models::ScannedData& data) = 0;
    virtual int addInfoToScannedDataAndSaveItToDataBase(ac::models::ScannedData& data) = 0;
    virtual int checkFunctionalityAndUpdateStatus() = 0;
};
#endif //CONTROLLERS_DEVICEMANAGER_HPP
