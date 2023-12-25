#include <iostream>
#include <string>
#include <unordered_map>

#include "../constants.h"
#include "../station/Station.h"
#include "../util/util.h"

std::unordered_map<StationId, Station*> Station::stationInstances;
std::vector<std::pair<int, PassengerCategory>> getSortedPassengerCount(Station* station);
bool passengerCountComparator(std::pair<int, PassengerCategory> &a, std::pair<int, PassengerCategory> &b);


Station::Station(StationId stationId)
{
    this->stationId = stationId;
    this->amountCollected = 0;
    this->discountOffered = 0;
    this->passengerCount = {{PassengerCategory::ADULT, 0}, {PassengerCategory::KID, 0}, {PassengerCategory::SENIOR_CITIZEN, 0}};
}

std::unordered_map <PassengerCategory, int> Station::getPassengerCount() {
    return this->passengerCount;
}

double Station::getServiceFeePercent() {
    return Station::SERVICE_FEE_PERCENT;
}

double Station::getReturnDiscountPercent() {
    return Station::RETURN_DISCOUNT_PERCENT;
}

void Station::updateAmountCollected(double amount) {
    this->amountCollected += amount;
}

void Station::updateDiscountOffered(double discountOffered) {
    this->discountOffered += discountOffered;
}

void Station::updatePassengerCount(PassengerCategory passengerCategory) {
    this->passengerCount[passengerCategory]++;
}

Station* Station::getInstance(StationId stationId) {
    if (Station::stationInstances.find(stationId) == Station::stationInstances.end()) {
        Station* stationInstance = new Station(stationId);
        Station::stationInstances[stationId] = stationInstance;
    }
    return Station::stationInstances[stationId];
}

void Station::printSummary() {
    std::cout << "TOTAL_COLLECTION " << getStationNameStringFromEnum(stationId) << " " << this->amountCollected
        << " " << this->discountOffered << std::endl;
    std::vector<std::pair<int, PassengerCategory>> countStorage = getSortedPassengerCount(this);
    std::cout << "PASSENGER_TYPE_SUMMARY" << std::endl;
    for (auto pCount : countStorage) {
        if (pCount.first)
                std::cout << getPassengerTypeStringFromEnum(pCount.second) << " " << pCount.first << std::endl;
    }
}

std::vector<std::pair<int, PassengerCategory>> getSortedPassengerCount(Station* station) {
    std::vector<std::pair<int, PassengerCategory>> result;
    std::unordered_map<PassengerCategory, int> passengerCount = station->getPassengerCount();
    for (auto it = passengerCount.begin(); it != passengerCount.end(); it++) {
        std::pair<int, PassengerCategory> count = {it->second, it->first};
        result.push_back(count);
    }
    sort(result.begin(), result.end(), passengerCountComparator);
    return result;
}

bool passengerCountComparator(std::pair<int, PassengerCategory> &a, std::pair<int, PassengerCategory> &b) {
    return (a.first > b.first) || (a.first == b.first && a.second < b.second);
}
