#ifndef STATION_H
#define STATION_H

#include <string>
#include <unordered_map>

#include "util/util.h"

using namespace std;

class Station
{
private:
    StationId stationId;
    double amountCollected;
    double discountOffered;
    unordered_map <PassengerCategory, int> passengerCount;
public:
    Station(StationId stationId);
    ~Station();
    void updateAmountCollected(double amount);
    void updateDiscountOffered(double amount);
    void updatePassangerCount(PassengerCategory passangerCategory);
    void printSummary();
};

#endif