#ifndef STATION_H
#define STATION_H

#include <string>
#include <unordered_map>

#include "constants.h"

using namespace std;

class Station
{
private:
    StationId stationId;
    double amountCollected;
    double discountOffered;
    unordered_map <PassengerCategory, int> passengerCount;
    static unordered_map<StationId, Station*> stationInstances;
public:
    Station(StationId stationId);
    ~Station();
    unordered_map <PassengerCategory, int> getPassengerCount();
    void updateAmountCollected(double amount);
    void updateDiscountOffered(double amount);
    void updatePassangerCount(PassengerCategory passangerCategory);
    void printSummary();
    static Station* getInstance(StationId stationId);
};

#endif