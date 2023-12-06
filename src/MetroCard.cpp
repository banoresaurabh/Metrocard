#include <iostream>
#include <string>
#include "MetroCard.h"

using namespace std;

unordered_map<string, MetroCard*> MetroCard:: metroCardInstances;

MetroCard::MetroCard(string id) {
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

MetroCard* MetroCard::getInstance(string id) {
    if (metroCardInstances.find(id) != metroCardInstances.end()) {
        return metroCardInstances[id];
    }
    MetroCard* metroCardInstance = new MetroCard(id);
    metroCardInstances[id] = metroCardInstance;
    return metroCardInstances[id];
}