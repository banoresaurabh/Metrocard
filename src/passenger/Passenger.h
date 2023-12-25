#ifndef PASSENGER_H
#define PASSENGER_H

#include "../constants.h"
#include "../card/MetroCard.h"

class Passenger {
    private:
        MetroCard *metroCard;
        PassengerCategory passengerCategory;
        bool returnDiscount;
        static std::unordered_map<std::string, Passenger*> passengerInstances;
    public:
        Passenger(PassengerCategory passengerCategory, std::string &metroCardId);
        ~Passenger();

        void checkIn(std::string metroCardId, PassengerCategory passengerCategory,
                    StationId fromStation);
        double getJourneyCharge(double ticketRate, double discount);
        double getJourneyDiscount(double ticketRate);
        static Passenger* getInstance(std::string metroCardId, PassengerCategory passengerCategory);
};

#endif
