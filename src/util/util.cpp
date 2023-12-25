#include <string>

#include "../constants.h"
#include "util.h"

std::string getStationNameStringFromEnum(StationId stationId) {
    switch(stationId) {
        case StationId::AIRPORT:
            return "AIRPORT";
        case StationId::CENTRAL:
            return "CENTRAL";
        default:
            return "UNKNOWN";
    }
}

StationId getStationNameEnumFromString(std::string stationId) {
    if (stationId == "AIRPORT") 
        return StationId::AIRPORT;
    if (stationId == "CENTRAL")
        return StationId::CENTRAL;
}

std::string getPassengerTypeStringFromEnum(PassengerCategory passengerCategory) {
    switch(passengerCategory) {
        case PassengerCategory::ADULT:
            return "ADULT";
        case PassengerCategory::KID:
            return "KID";
        case PassengerCategory::SENIOR_CITIZEN:
            return "SENIOR_CITIZEN";
        default:
            return "UNKNOWN";
    }
}

PassengerCategory getPassengerTypeEnumFromString(std::string passengerCategory) {
    if (passengerCategory == "ADULT")
        return PassengerCategory::ADULT;
    if (passengerCategory == "KID")
        return PassengerCategory::KID;
    if (passengerCategory == "SENIOR_CITIZEN")
        return PassengerCategory::SENIOR_CITIZEN;
}
