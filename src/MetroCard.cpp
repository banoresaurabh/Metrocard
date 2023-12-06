#include <iostream>
#include <string>
#include "MetroCard.h"

using namespace std;

MetroCard::MetroCard(string id) {
    this->id = id;
    this->balance = 0;
}

double MetroCard::getBalance() {
    return this->balance;
}