//
// Created by lukas on 12/5/2021.
//

#ifndef CONTROLLERS_TRANSLATORS_HPP
#define CONTROLLERS_TRANSLATORS_HPP


#include <string>
#include "CustomEnumTypes.hpp"
namespace ac{
namespace translators {
std::string getResultName(ScanResult result);
std::string getDeviceConnectionStatusName(DeviceConnectionStatus status);
std::string getDeviceFuntionalStatusName(DeviceFunctionalStatus status);
}
}

#endif //CONTROLLERS_TRANSLATORS_HPP
