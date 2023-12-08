#include <iostream>
#include <unordered_map>

#include "constants.h"
#include "MetroCard.h"
#include "Passenger.h"
#include "Station.h"

using namespace std;

unordered_map<string, Passenger*> Passenger::passengerInstances;

Passenger::Passenger(PassengerCategory passengerCategory, string metroCardId) {
    this->passengerCategory = passengerCategory;
    this->metroCard = MetroCard::getInstance(metroCardId);
    this->returnDiscount = false;
}

void Passenger::checkIn(string metroCardId, PassengerCategory passengerCategory,
                        StationId fromStation) {
    Station* station = Station::getInstance(fromStation);
    Passenger* passenger = Passenger::getInstance(metroCardId, passengerCategory);

    double ticketRate = RATES.at(this->passengerCategory);
    double discount = getJournyDiscount(ticketRate);
    double charge = getJournyCharge(ticketRate, discount);

    station->updateAmountCollected(charge);
    station->updateDiscountOffered(discount);
    station->updatePassangerCount(passengerCategory);
    this->returnDiscount = !this->returnDiscount;
}

double Passenger::getJournyCharge(double ticketRate, double discount) {
    double totalCharge = 0;
    double balance = this->metroCard->getBalance();
    double requiredAmount = (ticketRate - discount);
    // Collect service charge and refill card
    if (balance < (requiredAmount)) {
        double refillAmount = requiredAmount - balance;
        this->metroCard->setBalance(requiredAmount); 
        totalCharge += refillAmount * (Station::getServiceFeePercent());
    }

    // TODO: make it atomic
    this->metroCard->setBalance(this->metroCard->getBalance() - requiredAmount);
    totalCharge += requiredAmount;
    
    return totalCharge;
}

double Passenger::getJournyDiscount(double ticketRate) {
    double totalDiscount = 0;
    if (!this->returnDiscount) return totalDiscount;
    totalDiscount = ticketRate * (Station::getReturnDiscountPercent());
    return totalDiscount;
}

Passenger* Passenger::getInstance(string metroCardId, PassengerCategory passengerCategory) {
    if (passengerInstances.find(metroCardId) == passengerInstances.end()) {
        Passenger* passengerInstance = new Passenger(passengerCategory, metroCardId);
        passengerInstances[metroCardId] = passengerInstance;
    }
    return passengerInstances[metroCardId];
}

Passenger::~Passenger() {
    delete this->metroCard;
}
