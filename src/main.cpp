#include <fstream>
#include <iostream>

#include "constants.h"
#include "MetroCard.h"
#include "Passenger.h"
#include "Station.h"
#include "util.h"

using namespace std;

int main() {
    ifstream input("../input/input.txt");

    string command = "";
    while (input >> command){
        if (command == "BALANCE") {
            string balance, metroCardId;
            input >> metroCardId >> balance;
            MetroCard* metroCard = MetroCard::getInstance(metroCardId);
            metroCard->setBalance(stod(balance));
        } else if (command == "CHECK_IN") {
            string passengerCategory = "", fromStation = "", metroCardId = "";
            input >> metroCardId >> passengerCategory >> fromStation;
            Passenger* passenger = Passenger::getInstance(metroCardId, 
                                    getPassengerTypeEnumFromString(passengerCategory));
            passenger->checkIn(metroCardId, getPassengerTypeEnumFromString(passengerCategory),
                                    getStationNameEnumFromString(fromStation));
        } else if (command == "PRINT_SUMMARY") {
            Station* central = Station::getInstance(CENTRAL);
            Station* airport = Station::getInstance(AIRPORT);
            if (central != nullptr) {
                central->printSummary();
            }
            if (airport != nullptr) {
                airport->printSummary();
            }
        } 
    }
    return 0;
}