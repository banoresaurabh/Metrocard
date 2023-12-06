#include <iostream>
#include <string>
#include <unordered_map>

#include "Station.h"
#include "constants.h"
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

void Station::updateAmountCollected(double amount) {
    this->amountCollected += amount;
    // cout<<" Updating amount "<<this->amountCollected<<" for "<<getStationNameStringFromEnum(this->stationId)<<endl;
}

void Station::updateDiscountOffered(double discountOffered) {
    this->discountOffered += discountOffered;
    // cout<<" Updating discount "<<this->discountOffered<<endl;
}

void Station::updatePassangerCount(PassengerCategory passangerCategory) {
    this->passengerCount[passangerCategory]++;
}

Station* Station::getInstance(StationId stationId) {
    if (Station::stationInstances.find(stationId) != Station::stationInstances.end()) {
        return Station::stationInstances[stationId];
    }
    Station* stationInstance = new Station(stationId);
    Station::stationInstances[stationId] = stationInstance;
    return Station::stationInstances[stationId];
}

void Station::printSummary() {
    cout<<"TOTAL_COLLECTION "<<getStationNameStringFromEnum(stationId)<<" "<<this->amountCollected
        <<" "<<this->discountOffered<<endl;
    vector<pair<int, PassengerCategory>> countStorage = getSortedPassengerCount(this);
    cout<<"PASSENGER_TYPE_SUMMARY"<<endl;
    for (auto pCount : countStorage) {
        PassengerCategory category = static_cast<PassengerCategory>(pCount.second);
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
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}