//
// Created by lukas on 12/5/2021.
//

#pragma once
#ifndef CONTROLLERS_CUSTOMENUMTYPES_HPP
#define CONTROLLERS_CUSTOMENUMTYPES_HPP

enum ScanResult{
    Healthy = 1 , Unrecognized = 0, Unhealthy =  - 1
};

enum DeviceConnectionStatus{
    Yes = 1 , Error = 0, No =  - 1
};

enum DeviceFunctionalStatus{
     DeviceNotFound = 0, ConnectionUnstable = 1 , Alright =  2
};

#endif //CONTROLLERS_CUSTOMENUMTYPES_HPP
