#ifndef UTIL_H
#define UTIL_H

#include "constants.h"

using namespace std;

string getStationNameStringFromEnum(StationId stationId);
StationId getStationNameEnumFromString(string stationId);
string getPassengerTypeStringFromEnum(PassengerCategory passengerCategory);
PassengerCategory getPassengerTypeEnumFromString(string passengerCategory);
#endif