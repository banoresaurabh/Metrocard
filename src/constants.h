#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const enum PassengerCategory {
    ADULT,
    KID,
    SENIOR_CITIZEN
};

const enum StationId {
    AIRPORT,
    CENTRAL
};

const unordered_map<int, double> RATES({
    {ADULT, 200.0},
    {KID, 50.0},
    {SENIOR_CITIZEN, 100.0}
});

const static double SERVICE_FEE_PERCENT = 2;
const static double RETURN_DISCOUNT_PERCENT = 50;

#endif