//
// Created by lukas on 07/11/2021.
//

#include <iostream>
#include "MsgManager.hpp"
#include <algorithm>
#include <math.h>
#include <qDebug>

////////////////// CMD
std::vector<uint8_t> MsgManager::cmdOut1() {
    auto cmd = CommandProvider::cmdOut1();
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}

std::vector<uint8_t> MsgManager::cmdOut2() {
    auto cmd = CommandProvider::cmdOut2();
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}

std::vector<uint8_t> MsgManager::cmdOut3() {
    auto cmd = CommandProvider::cmdOut3();
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}

std::vector<uint8_t> MsgManager::cmdOutA() {
    auto cmd = CommandProvider::cmdOutA();
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}


std::vector<uint8_t> MsgManager::cmdProfileMemoryAddress() {
    auto cmd = CommandProvider::cmdProfileMemoryAddress();
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}

std::vector<uint8_t> MsgManager::cmdProfileSizeAndTimeInfo(const uint32_t& memoryAddress, const uint8_t rlen) {
    auto cmd = CommandProvider::cmdProfileSizeAndTimeInfo(memoryAddress, rlen);
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}

std::vector<uint8_t> MsgManager::cmdValueFromMemoryAddress(const uint32_t& memoryAddress, const uint8_t rlen) {
    auto cmd = CommandProvider::cmdValueFromMemoryAddress(memoryAddress, rlen);
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}

std::vector<uint8_t> MsgManager::cmdProfileAndMeasuredValueAddress() {
    auto cmd = CommandProvider::cmdProfileAndMeasuredValueAddress();
    cmd.push_back(calculateCheckSumForCommand(cmd));
    return cmd;
}


////////////////// Translators - U2 coding
int MsgManager::translateUint16ToIntU2Coded(uint16_t rawValue)
{
    bool isNegative = rawValue & 0x8000;
    //getting rid of sign and concatenating,  2 * 0x8000 -> single 0x8000 is getting rid off sign, second is using that sign accroding to u2 coding
    return isNegative ? (rawValue - 2*0x8000) : rawValue;
}

int MsgManager::translateMsgToOutNValue(const std::vector<uint8_t>& message) {
    int receivedValue = (uint16_t) message[6] << 8 | message[7];
    return translateUint16ToIntU2Coded(receivedValue);
}

uint32_t MsgManager::translateMsgToProfileMemoryAddress(const std::vector<uint8_t>& message) {
    uint32_t receivedValue =
            (uint32_t) message[4] << 24 | (uint32_t) message[5] << 16 | (uint16_t) message[6] << 8 | message[7];
    return receivedValue;
}

std::pair<uint16_t, uint16_t>
MsgManager::translateUnknownSizedMsgToRawSizeAndTimeInfo(const std::vector<uint8_t>& message) {
    std::pair<uint16_t, uint16_t> rawData{0, 0};
    auto dataLength = message.size() - 10;
    switch (dataLength) {
    case 2: //only sizeInfoWasSend
        rawData = translateMsgToRawSizeAndTimeInfo(message, false);
        break;

    case 4:
        rawData = translateMsgToRawSizeAndTimeInfo(message, true);
        break;
    default:
        std::cout
                << "TRANSLATION FAILURE - arg MESSAGE has WRONG SIZE - cmd translateMsgToProfileMemoryAddress FAILED"
                << std::endl;
        return {};
    }

    auto[sizeInProfiles, timeInfo] = MsgManager::translateRawSizeAndTimeInfo(rawData);
            return {sizeInProfiles, timeInfo};
}

std::pair<uint16_t, uint16_t>
MsgManager::translateMsgToRawSizeAndTimeInfo(const std::vector<uint8_t>& message, bool isTimeInfoInMessage) {
    uint16_t size = (uint16_t) message[8] << 8 | message[9];
    if (!isTimeInfoInMessage) {
        return std::pair<uint16_t, uint16_t>{size, 0};
    }
    uint16_t timeInfo = (uint16_t) message[10] << 8 | message[11];
    return std::pair<uint16_t, uint16_t>{size, timeInfo};
}

std::vector<std::pair<uint16_t, uint16_t>>
MsgManager::translateRawDataPointIntoPairXY(std::vector<uint8_t> ungroupDataPoints) {

    if (ungroupDataPoints.size() % 4 != 0) {
        std::cout
                << "\n\n TRANSLATION FAILURE - arg ungroupDataPointsDIV IS NOT DIV BY 4 - cmd translateRawDataPointIntoPairXY"
                << std::endl;
        return {};
    }
    std::vector<std::pair<uint16_t, uint16_t>> groupedDataPoints;
    while (!ungroupDataPoints.empty()) {
        auto itX = ungroupDataPoints.begin();
        auto itY = itX + 2;
        uint16_t x = (uint16_t) *itX << 8 | *(itX + 1);
        uint16_t y = (uint16_t) *itY << 8 | *(itY + 1);
        auto xy = std::make_pair(x, y);
        groupedDataPoints.push_back(xy);
        ungroupDataPoints.erase(itX, (itY + 1) + 1);
    }

    return groupedDataPoints;
}

std::vector<std::pair<int, int> > MsgManager::translateUint16PairXYToIntPairXY(const std::vector<std::pair<uint16_t, uint16_t>>& uint16PairsXY)
{
    std::vector<std::pair<int,int>> intPairsXY = {};
    for(auto uint16Pair : uint16PairsXY){
        int x = translateUint16ToIntU2Coded(uint16Pair.first);
        int y = translateUint16ToIntU2Coded(uint16Pair.second);
        auto xy = std::make_pair(x,y);
        intPairsXY.push_back(xy);
    }
    return intPairsXY;
}

std::pair<uint16_t, float> MsgManager::translateRawSizeAndTimeInfo(std::pair<uint16_t, uint16_t>& pair) {
    uint16_t size = pair.first / 32;
    float timeInfo = pair.second * 0.1; //ms
    return {size, timeInfo};
}

///////////////// Message Checkers

std::optional<std::string>
MsgManager::isMessageInvalid(const std::vector<uint8_t>& message, const size_t& requiredSize, int sizeComparisonType) {
    if(message.empty()){
        return "ERROR - MESSAGE IS EMPTY";
    }
    std::string errorInfo = isItErrorMessage(message);
    bool crcAndSizeCorrectness = not message.empty() and isMessageCrcValueCorrect(message) and
            isMessageSizeCorrect(message.size(), requiredSize, sizeComparisonType);
    if(crcAndSizeCorrectness){
        return std::nullopt;
    }else{
        return  isItErrorMessage(message);
    }
}

bool MsgManager::isMessageCrcValueCorrect(const std::vector<uint8_t>& message) {
    if (message.size() < 3) {
        return false;
    }
    return calculateCheckSumForReceivedMessage(message) == *(message.cend() - 1);
}

bool MsgManager::isMessageSizeCorrect(const int& messageSize, const int& requiredMessageSize, int typeOfComparison) {
    switch (typeOfComparison) {
    case (2):
        return messageSize > requiredMessageSize;
    case (1):
        return messageSize >= requiredMessageSize;
    case (0):
        return messageSize == requiredMessageSize;
    case (-1):
        return messageSize <= requiredMessageSize;
    case (-2):
        return messageSize < requiredMessageSize;
    default:
        return false;
    }
}

std::string MsgManager::isItErrorMessage(const std::vector<uint8_t>& message) {
    std::string result{};
    if (message[2] != ErrorProvider::errorFirsByte or not isMessageSizeCorrect(message.size(),4,1)) {
        return result;
    } else {
        uint8_t errorCode = message[3];
        auto errorMap = ErrorProvider::getErrorMap();
        auto it = errorMap.find(errorCode);
        if (it != errorMap.end()) {
            result += it->second;
        } else {
            result += "UNKNOWN ERROR - last byte = " + std::to_string(errorCode);
        }
    }
    return result;
}

////Message Modifiers
// do not use -> zwracaja vectory z blednym sizem dla duzych wektorow , cuda sie tu dzieja potencjalnie zmien na reference
std::vector<uint8_t>
MsgManager::getMessageFromStartSignToEndSign(std::vector<uint8_t> message, uint8_t startSign, uint8_t endSign,
                                             bool areStartAndStopSignsLeftInResultStream) {
    // bool wasMsgUpdated = false;
    while (*message.cbegin() != startSign) {
        message.erase(message.begin());
    }
    //-2 'cause after etx sign 0x03 is crcSum
    while (*(message.cend() - 2) != endSign) {
        message.erase(message.end() - 1);
    }

    if (!areStartAndStopSignsLeftInResultStream) {
        message.erase(message.begin());
        message.erase(message.end() - 1);
    }

    return message;
}

std::vector<uint8_t> MsgManager::getClearedMessageFromStream(std::vector<uint8_t> message) {
    return getMessageFromStartSignToEndSign(message, 0x02, 0x03);
}

std::vector<std::pair<int, int>> MsgManager::getFiltredAndWindowedIntPairsXY(const std::vector<std::pair<uint16_t, uint16_t>>& uint16PairsXY)
{
    std::vector<std::pair<int, int>> intPairsXY = translateUint16PairXYToIntPairXY(uint16PairsXY);
    std::vector<std::pair<int, int>> checkedPairsXY  = getClearedAndSortedPairsXY(intPairsXY);
    std::vector<std::pair<int, int>> filteredPairsXY = getFiltredPairsXY(checkedPairsXY);
    std::vector<std::pair<int, int>> windowedPairsXY = getWindowedPairsXYUsingDerivative(filteredPairsXY);
    standardizePairsXYToStartFromZero(windowedPairsXY);
    invertProfile(windowedPairsXY);
    return windowedPairsXY;
}




////Helpers
uint8_t
MsgManager::calculateCheckSum(const std::vector<uint8_t>& message, const uint8_t startBit, const uint8_t endBit) {
    uint8_t checkSum{0};
    auto msgSize = message.size();
    auto absoluteEndBit = msgSize - endBit - 1;

    for (std::vector<uint8_t>::size_type i = 0; i < message.size(); i++) {
        if (absoluteEndBit < i or i < startBit) {
            continue;
        }
        checkSum ^= message[i];
    }
    return checkSum;
}

uint8_t MsgManager::calculateCheckSumForCommand(const std::vector<uint8_t>& message) {
    return calculateCheckSum(message, 1, 1);
}

uint8_t MsgManager::calculateCheckSumForReceivedMessage(const std::vector<uint8_t>& message) {
    return calculateCheckSum(message, 1, 2);
}


std::vector<std::pair<int,int>> MsgManager::getClearedAndSortedPairsXY(const std::vector<std::pair<int,int>>& pairsXY){

    std::vector<std::pair<int, int>> clearPairsXY = {};
    std::vector<int> invalidValues = {-1,32767};

    for(auto pair : pairsXY){
        int x = pair.first;
        int y = pair.second;

        if(std::find(invalidValues.begin(), invalidValues.end(), x) != invalidValues.end()){
            continue;
        }
        if(std::find(invalidValues.begin(), invalidValues.end(), y) != invalidValues.end()){
            continue;
        }

        auto xy = std::make_pair(x,y);
        clearPairsXY.push_back(xy);
    }
    std::sort(clearPairsXY.begin(),clearPairsXY.end());
    return clearPairsXY;
}


//Profile Manipulation Helpers
std::vector<std::pair<int, int>> MsgManager::getFiltredPairsXY(const std::vector<std::pair<int, int> > &pairsXY)
{
    std::vector<std::pair<int, int>> filteredPairsXY = {};

    int rangeOfCalculatedAvg = 9; //range of average calculation
    float maxAvgDivergence = 0.5;

    for(auto it = pairsXY.begin();it != pairsXY.end(); it ++){
        int quantity = 0;
        double sum   = 0;
        int firsRelativeIndex = - rangeOfCalculatedAvg / 2; //left end of range
        int lastRelativeIndex =   rangeOfCalculatedAvg / 2 + 1; //right end of range

        for(int i = firsRelativeIndex ; i < lastRelativeIndex; i ++){

            if((it + i) != pairsXY.begin() && (it + i) != pairsXY.end()){
                quantity ++;
                sum += (it + i)->second;
            }

        }

        double avg = sum / quantity;

        //value cannot be different more than 50% from average (maxAvgDivergance)
        float diffInPercentage = std::abs( (float) it->second/avg -1.0);
        if(diffInPercentage < maxAvgDivergence){
            auto xy = std::make_pair(it->first,it->second);
            filteredPairsXY.push_back(xy);
        }
    }

    return filteredPairsXY;
}


std::vector<std::pair<int, int>> MsgManager::getWindowedPairsXYUsingPercentage(const std::vector<std::pair<int, int> > &pairsXY){
    int middlePairIndex = pairsXY.size() / 2; //hopefully its part of seed profile
    auto middlePairIt = pairsXY.begin() + middlePairIndex;
    bool areElementsLeftInFront = true;
    bool areElementsLeftInBack  = true;
    int radius = 1;

    std::vector<std::pair<int, int>> windowedPairsXY = { *middlePairIt };
    float maxSlopeDivergance = 1.2;

    //implementation recognize the end of seed profile as a big value decrease, steep slope
    while(areElementsLeftInFront or areElementsLeftInBack){

        //front -> left side of chart
        if( areElementsLeftInFront && (middlePairIt - radius) != pairsXY.begin() ){ //can I still go further
            if((middlePairIt - radius)->second != 0){ //can I divide
                //element before divided by element after -> overall difference in percent
                float diffInPercentage = std::abs( (float) (middlePairIt - radius + 1)->second / (float) (middlePairIt - radius)->second - 1.0);
                if(diffInPercentage > maxSlopeDivergance){
                    areElementsLeftInFront = false;
                    continue;
                }else{
                    windowedPairsXY.insert(windowedPairsXY.begin(),*(middlePairIt - radius));
                }
            }

        }else{
            areElementsLeftInFront = false;
        }

        //back -> right side of chart
        if( areElementsLeftInBack && (middlePairIt + radius) != pairsXY.end() ){
            if((middlePairIt + radius)->second != 0){
                float diffInPercentage = std::abs( (float) (middlePairIt + radius - 1)->second / (float) (middlePairIt + radius)->second - 1.0);
                if(diffInPercentage > maxSlopeDivergance){
                    areElementsLeftInBack = false;
                    continue;
                }else{
                    windowedPairsXY.push_back(*(middlePairIt + radius));
                }
            }
        }else{
            areElementsLeftInBack = false;
        }


        radius ++;
    }
    return windowedPairsXY;
}

std::vector<std::pair<int, int>> MsgManager::getWindowedPairsXYUsingDerivative(const std::vector<std::pair<int, int> > &pairsXY){

    int middlePairIndex = pairsXY.size() / 2; //hopefully its part of seed profile
    auto middlePairIt = pairsXY.begin() + middlePairIndex;
    bool areElementsLeftInFront = true;
    bool areElementsLeftInBack  = true;
    int radius = 1;
    std::vector<std::pair<int, int>> windowedPairsXY = { *middlePairIt };
    float maxAngle = 80;
    float maxDerivative = tan(maxAngle * 3.14 /180);

    //implementation recognize the end of seed profile as steep slope pitched up or down
    while(areElementsLeftInFront or areElementsLeftInBack){

        //front -> left side of chart
        if(areElementsLeftInFront && (middlePairIt - radius) != pairsXY.begin() ){ //can I still go further
            float dy = (middlePairIt - radius + 1)->second - (middlePairIt - radius)->second;
            float dx = (middlePairIt - radius + 1)->first  - (middlePairIt - radius)->first;
            if(dx != 0){
                float derivative = std::abs(dy/dx);
                if(derivative > maxDerivative){
                    areElementsLeftInFront = false;
                    continue;
                }else{
                    windowedPairsXY.insert(windowedPairsXY.begin(),*(middlePairIt - radius));
                }
            }
        }else{
            areElementsLeftInFront = false;
        }


        //back -> right side of chart
        if(areElementsLeftInBack && (middlePairIt + radius) != pairsXY.end() ){
            float dy = (middlePairIt + radius)->second - (middlePairIt + radius - 1)->second;
            float dx = (middlePairIt + radius)->first  - (middlePairIt + radius - 1)->first;
            if(dx != 0){
                float derivative = std::abs(dy/dx);
                if(derivative > maxDerivative){
                    areElementsLeftInBack = false;
                    continue;
                }else{
                    windowedPairsXY.push_back(*(middlePairIt + radius));
                }
            }
        }

        radius ++;
    }
    return windowedPairsXY;
}

void MsgManager::standardizePairsXYToStartFromZero(std::vector<std::pair<int,int>>& pairsXY){
    auto minY = *std::min_element(pairsXY.cbegin(), pairsXY.cend(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });
    auto minX = *std::min_element(pairsXY.cbegin(), pairsXY.cend(), [](const auto& lhs, const auto& rhs) {
        return lhs.first < rhs.first;
    });

    for(auto& pair : pairsXY){
        pair.first  -= minX.first;
        pair.second -= minY.second;
    }
}

void MsgManager::invertProfile(std::vector<std::pair<int,int>>& pairsXY){

    auto max = *std::max_element(pairsXY.cbegin(), pairsXY.cend(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;});

    for(auto& pair : pairsXY){
        pair.second -= max.second;
        pair.second = pair.second * -1;
    }
}












