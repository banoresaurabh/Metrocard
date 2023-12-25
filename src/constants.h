#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <unordered_map>
#include <vector>

const enum class PassengerCategory {
    ADULT,
    KID,
    SENIOR_CITIZEN
};

const enum class StationId {
    AIRPORT,
    CENTRAL
};

const std::unordered_map<PassengerCategory, double> RATES({
    {PassengerCategory::ADULT, 200.0},
    {PassengerCategory::KID, 50.0},
    {PassengerCategory::SENIOR_CITIZEN, 100.0}
});

#endif
