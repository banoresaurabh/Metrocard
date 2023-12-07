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
    constexpr static double SERVICE_FEE_PERCENT = 0.02;
    constexpr static double RETURN_DISCOUNT_PERCENT = 0.50;
public:
    Station(StationId stationId);
    ~Station();
    unordered_map <PassengerCategory, int> getPassengerCount();
    static Station* getInstance(StationId stationId);
    static double getServiceFeePercent();
    static double getReturnDiscountPercent();
    
    void updateAmountCollected(double amount);
    void updateDiscountOffered(double amount);
    void updatePassangerCount(PassengerCategory passangerCategory);
    void printSummary();
    
};

#endif
