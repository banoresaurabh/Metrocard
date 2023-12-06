#include <iostream>
#include <unordered_map>

#include "Passenger.h"
#include "MetroCard.h"
#include "Station.h"
#include "constants.h"

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
        totalCharge += refillAmount * (SERVICE_FEE_PERCENT / 100);
    }

    // TODO: make it atomic
    this->metroCard->setBalance(this->metroCard->getBalance() - requiredAmount);
    totalCharge += requiredAmount;
    
    return totalCharge;
}

double Passenger::getJournyDiscount(double ticketRate) {
    double totalDiscount = 0;
    if (!this->returnDiscount) return totalDiscount;
    totalDiscount = ticketRate * (RETURN_DISCOUNT_PERCENT / 100);
    return totalDiscount;
}

Passenger* Passenger::getInstance(string metroCardId, PassengerCategory passengerCategory) {
    if (passengerInstances.find(metroCardId) != passengerInstances.end()) {
        return passengerInstances[metroCardId];
    }
    Passenger* passengerInstance = new Passenger(passengerCategory, metroCardId);
    passengerInstances[metroCardId] = passengerInstance;
    return passengerInstances[metroCardId];
}

Passenger::~Passenger() {
    delete this->metroCard;
}