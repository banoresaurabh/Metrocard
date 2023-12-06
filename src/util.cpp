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


/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Include necessary headers for your project
#include "MetroCard.h"
#include "Passenger.h"
#include "Station.h"

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Assume you have initialized your MetroCard, Passenger, and Station instances

    string command;
    while (inputFile >> command) {
        if (command == "BALANCE") {
            // Read the MetroCard number and balance
            int metroCardNumber;
            double balance;
            inputFile >> metroCardNumber >> balance;

            // Process the BALANCE command
            // Your logic to handle BALANCE command...
        } else if (command == "CHECK_IN") {
            // Read the MetroCard number, passenger type, and from station
            int metroCardNumber;
            string passengerType, fromStation;
            inputFile >> metroCardNumber >> passengerType >> fromStation;

            // Process the CHECK_IN command
            // Your logic to handle CHECK_IN command...
        } else if (command == "PRINT_SUMMARY") {
            // Process the PRINT_SUMMARY command
            // Your logic to handle PRINT_SUMMARY command...
        } else {
            cerr << "Error: Unknown command in input file." << endl;
            return 1;
        }
    }

    inputFile.close();

    return 0;
}

*/