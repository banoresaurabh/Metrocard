#ifndef PASSENGER_H
#define PASSENGER_H

#include "constants.h"
#include "MetroCard.h"

using namespace std;

class Passenger {
    private:
        MetroCard *metroCard;
        PassengerCategory passengerCategory;
        bool returnDiscount;
        static unordered_map<string, Passenger*> passengerInstances;
    public:
        Passenger(PassengerCategory passengerCategory, string metroCardId);
        ~Passenger();

        void checkIn(string metroCardId, PassengerCategory passengerCategory,
                    StationId fromStation);
        double getJournyCharge(double ticketRate, double discount);
        double getJournyDiscount(double ticketRate);
        static Passenger* getInstance(string metroCardId, PassengerCategory passengerCategory);
};

#endif
