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
    CENTRAL,
    AIRPORT
};

const unordered_map<int, double> RATES({
    {ADULT, 200.0},
    {KID, 100.0},
    {SENIOR_CITIZEN, 150.0}
});

#endif