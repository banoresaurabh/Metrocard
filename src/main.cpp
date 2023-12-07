#include <fstream>
#include <iostream>

#include "constants.h"
#include "MetroCard.h"
#include "Passenger.h"
#include "Station.h"
#include "util.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2){
        cout<<"No path found for input file"<<endl;
        return 1;
    } 
    string input_file = argv[1];
    ifstream input(input_file);

    string command;
    while (input >> command){
        if (command == "BALANCE") {
            string balance, metroCardId;

            input >> metroCardId >> balance;
            MetroCard* metroCard = MetroCard::getInstance(metroCardId);
            metroCard->setBalance(stod(balance));
        } else if (command == "CHECK_IN") {
            string passengerCategory, fromStation, metroCardId;

            input >> metroCardId >> passengerCategory >> fromStation;
            Passenger* passenger = Passenger::getInstance(metroCardId, 
                                    getPassengerTypeEnumFromString(passengerCategory));
            passenger->checkIn(metroCardId, getPassengerTypeEnumFromString(passengerCategory),
                                    getStationNameEnumFromString(fromStation));
        } else if (command == "PRINT_SUMMARY") {
            Station* central = Station::getInstance(CENTRAL);
            Station* airport = Station::getInstance(AIRPORT);

            central->printSummary();
            airport->printSummary();
        } 
    }
    return 0;
}
