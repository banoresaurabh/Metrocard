#ifndef UTIL_H
#define UTIL_H

#include "../constants.h"

std::string getStationNameStringFromEnum(StationId stationId);
StationId getStationNameEnumFromString(std::string stationId);
std::string getPassengerTypeStringFromEnum(PassengerCategory passengerCategory);
PassengerCategory getPassengerTypeEnumFromString(std::string passengerCategory);

#endif
