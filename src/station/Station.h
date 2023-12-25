#ifndef STATION_H
#define STATION_H

#include <string>
#include <unordered_map>

#include "../constants.h"

class Station
{
private:
    StationId stationId;
    double amountCollected;
    double discountOffered;
    std::unordered_map <PassengerCategory, int> passengerCount;

    static std::unordered_map<StationId, Station*> stationInstances;
    constexpr static double SERVICE_FEE_PERCENT = 0.02;
    constexpr static double RETURN_DISCOUNT_PERCENT = 0.50;
public:
    Station(StationId stationId);
    ~Station();
    std::unordered_map <PassengerCategory, int> getPassengerCount();
    static Station* getInstance(StationId stationId);
    static double getServiceFeePercent();
    static double getReturnDiscountPercent();
    
    void updateAmountCollected(double amount);
    void updateDiscountOffered(double amount);
    void updatePassengerCount(PassengerCategory passengerCategory);
    void printSummary();
    
};

#endif
