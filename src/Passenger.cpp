#include "Passenger.h"
#include "MetroCard.h"
#include "station.h"
#include "util/util.h"

using namespace std;

Passenger::Passenger(PassengerCategory passengerCategory, string metroCardId) {
    this->passengerCategory = passengerCategory;
    this->metroCard = new MetroCard(metroCardId);
    this->hasReturned = false;
}

void Passenger::checkIn(string metroCardId, PassengerCategory passengerCategory,
                        StationId fromStation) {
    Station station(fromStation);
    Passenger passenger(passengerCategory, metroCardId);
    double charge = getJournyCharge();
    double discount = getJournyDiscount();
    station.updateAmountCollected(charge);
    station.updateDiscountOffered(discount);
    station.updatePassangerCount(passengerCategory);
}

double Passenger::getJournyCharge() {
    double totalCharge = 0;
    return totalCharge;
}

double Passenger::getJournyDiscount() {
    double totalDiscount = 0;
    return totalDiscount;
}

Passenger::~Passenger() {
    delete this->metroCard;
}