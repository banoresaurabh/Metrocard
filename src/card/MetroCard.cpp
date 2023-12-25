#include <iostream>
#include <string>

#include "MetroCard.h"


std::unordered_map<std::string, MetroCard*> MetroCard:: metroCardInstances;

MetroCard::MetroCard(std::string id) {
    this->id = id;
    this->balance = 0;
}

MetroCard::~MetroCard() {
    delete this;
}

double MetroCard::getBalance() {
    return this->balance;
}

void MetroCard::setBalance(double balance) {
    this->balance = balance;
}

MetroCard* MetroCard::getInstance(std::string id) {
    if (metroCardInstances.find(id) == metroCardInstances.end()) {
        MetroCard* metroCardInstance = new MetroCard(id);
        metroCardInstances[id] = metroCardInstance;
    }
    return metroCardInstances[id];
}
