#ifndef PASSENGER_H
#define PASSENGER_H

using namespace std;

class Passenger {
    private:
        MetroCard *metroCard;
        PassengerCategory passengerCategory;
        bool hasReturned;
    public:
        Passenger(PassengerCategory passengerCategory, string metroCardId);
        ~Passenger();

        void checkIn(string metroCardId, PassengerCategory passengerCategory,
                    StationId fromStation);
        double getJournyCharge();
        double getJournyDiscount();
};

#endif
