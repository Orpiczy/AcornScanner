//
// Created by lukas on 12/5/2021.
//

#include "Translators.hpp"
namespace ac{
namespace translators {
std::string getResultName(ScanResult result) {

    switch (result) {
    case (ScanResult::Healthy):
        return "Healthy";
    case (ScanResult::Unrecognized):
        return "Unrecognized";
    case (ScanResult::Unhealthy):
        return "Unhealthy";
    default:
        return "Incorrect Result";
    }
}


std::string getDeviceConnectionStatusName(DeviceConnectionStatus status)
{
    switch (status) {
    case (DeviceConnectionStatus::Yes):
        return "Yes";
    case (DeviceConnectionStatus::Error):
        return "Error";
    case (DeviceConnectionStatus::No):
        return "No";
    default:
        return "Incorrect Status";
    }
}

std::string getDeviceFunctionalStatusName(DeviceFunctionalStatus status)
{
    switch (status) {
    case (DeviceFunctionalStatus::DeviceNotFound):
        return "DeviceNotFound";
    case (DeviceFunctionalStatus::ConnectionUnstable):
        return "ConnectionUnstable";
    case (DeviceFunctionalStatus::Alright):
        return "Alright";
    default:
        return "Incorrect Status";
    }
}

}
}
