#include <string>

#include "Station.h"
#include "util/util.h"

using namespace std;

Station::Station(StationId stationId)
{
    this->stationId = stationId;
    this->amountCollected = 0;
    this->discountOffered = 0;
    this->passengerCount = {{ADULT, 0}, {KID, 0}, {SENIOR_CITIZEN, 0}};
}

void Station::updateAmountCollected(double amount) {
    this->amountCollected += amount;
}

void Station::updateDiscountOffered(double amount) {
    this->discountOffered += discountOffered;
}

void Station::updatePassangerCount(PassengerCategory passangerCategory) {
    this->passengerCount[passangerCategory]++;
}

void Station::printSummary() {
    return;
}