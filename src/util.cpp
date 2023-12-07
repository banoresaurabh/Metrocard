#include <string>

#include "constants.h"
#include "util.h"

using namespace std;

string getStationNameStringFromEnum(StationId stationId) {
    switch(stationId) {
        case AIRPORT:
            return "AIRPORT";
        case CENTRAL:
            return "CENTRAL";
        default:
            return "UNKNOWN";
    }
}

StationId getStationNameEnumFromString(string stationId) {
    if (stationId == "AIRPORT") 
        return AIRPORT;
    if (stationId == "CENTRAL")
        return CENTRAL;
}

string getPassengerTypeStringFromEnum(PassengerCategory passengerCategory) {
    switch(passengerCategory) {
        case ADULT:
            return "ADULT";
        case KID:
            return "KID";
        case SENIOR_CITIZEN:
            return "SENIOR_CITIZEN";
        default:
            return "UNKNOWN";
    }
}

PassengerCategory getPassengerTypeEnumFromString(string passengerCategory) {
    if (passengerCategory == "ADULT")
        return ADULT;
    if (passengerCategory == "KID")
        return KID;
    if (passengerCategory == "SENIOR_CITIZEN")
        return SENIOR_CITIZEN;
}
