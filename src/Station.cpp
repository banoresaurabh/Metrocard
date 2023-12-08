#include <iostream>
#include <string>
#include <unordered_map>

#include "constants.h"
#include "Station.h"
#include "util.h"

using namespace std;

unordered_map<StationId, Station*> Station::stationInstances;
vector<pair<int, PassengerCategory>> getSortedPassengerCount(Station* station);
bool passengerCountComparator(pair<int, PassengerCategory> &a, pair<int, PassengerCategory> &b);


Station::Station(StationId stationId)
{
    this->stationId = stationId;
    this->amountCollected = 0;
    this->discountOffered = 0;
    this->passengerCount = {{ADULT, 0}, {KID, 0}, {SENIOR_CITIZEN, 0}};
}

unordered_map <PassengerCategory, int> Station::getPassengerCount() {
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

void Station::updatePassangerCount(PassengerCategory passangerCategory) {
    this->passengerCount[passangerCategory]++;
}

Station* Station::getInstance(StationId stationId) {
    if (Station::stationInstances.find(stationId) == Station::stationInstances.end()) {
        Station* stationInstance = new Station(stationId);
        Station::stationInstances[stationId] = stationInstance;
    }
    return Station::stationInstances[stationId];
}

void Station::printSummary() {
    cout<<"TOTAL_COLLECTION "<<getStationNameStringFromEnum(stationId)<<" "<<this->amountCollected
        <<" "<<this->discountOffered<<endl;
    vector<pair<int, PassengerCategory>> countStorage = getSortedPassengerCount(this);
    cout<<"PASSENGER_TYPE_SUMMARY"<<endl;
    for (auto pCount : countStorage) {
        if (pCount.first)
                cout<<getPassengerTypeStringFromEnum(pCount.second)<<" "<<pCount.first<<endl;
    }
}

vector<pair<int, PassengerCategory>> getSortedPassengerCount(Station* station) {
    vector<pair<int, PassengerCategory>> result;
    unordered_map <PassengerCategory, int> passengerCount = station->getPassengerCount();
    for (auto it = passengerCount.begin(); it != passengerCount.end(); it++) {
        pair<int, PassengerCategory> count = {it->second, it->first};
        result.push_back(count);
    }
    sort(result.begin(), result.end(), passengerCountComparator);
    return result;
}

bool passengerCountComparator(pair<int, PassengerCategory> &a, pair<int, PassengerCategory> &b) {
    return (a.first > b.first) || (a.first == b.first && a.second < b.second);
}
