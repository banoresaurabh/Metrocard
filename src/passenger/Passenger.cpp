#include <unordered_map>

#include "../constants.h"
#include "../card/MetroCard.h"
#include "../passenger/Passenger.h"
#include "../station/Station.h"

std::unordered_map<std::string, Passenger*> Passenger::passengerInstances;

Passenger::Passenger(PassengerCategory passengerCategory, std::string &metroCardId) {
    this->passengerCategory = passengerCategory;
    this->metroCard = MetroCard::getInstance(metroCardId);
    this->returnDiscount = false;
}

void Passenger::checkIn(std::string metroCardId, PassengerCategory passengerCategory,
                        StationId fromStation) {
    Station* station = Station::getInstance(fromStation);
    double ticketRate = RATES.at(this->passengerCategory);
    double discount = getJourneyDiscount(ticketRate);
    double charge = getJourneyCharge(ticketRate, discount);

    station->updateAmountCollected(charge);
    station->updateDiscountOffered(discount);
    station->updatePassengerCount(passengerCategory);
    this->returnDiscount = !this->returnDiscount;
}

double Passenger::getJourneyCharge(double ticketRate, double discount) {
    double totalCharge = 0;
    double balance = this->metroCard->getBalance();
    double requiredAmount = (ticketRate - discount);

    // Collect service charge and refill card
    if (balance < (requiredAmount)) {
        double refillAmount = requiredAmount - balance;
        this->metroCard->setBalance(requiredAmount); 
        totalCharge += refillAmount * (Station::getServiceFeePercent());
    }
    this->metroCard->setBalance(this->metroCard->getBalance() - requiredAmount);
    totalCharge += requiredAmount;
    
    return totalCharge;
}

double Passenger::getJourneyDiscount(double ticketRate) {
    double totalDiscount = 0;
    if (!this->returnDiscount) return totalDiscount;
    totalDiscount = ticketRate * (Station::getReturnDiscountPercent());
    return totalDiscount;
}

Passenger* Passenger::getInstance(std::string metroCardId, PassengerCategory passengerCategory) {
    if (passengerInstances.find(metroCardId) == passengerInstances.end()) {
        Passenger* passengerInstance = new Passenger(passengerCategory, metroCardId);
        passengerInstances[metroCardId] = passengerInstance;
    }
    return passengerInstances[metroCardId];
}

Passenger::~Passenger() {
    delete this->metroCard;
}
