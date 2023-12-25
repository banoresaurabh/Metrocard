#include "BalanceCommand.h"
#include "../card/MetroCard.h"

BalanceCommand::BalanceCommand(const std::string &balanceInp, const std::string &metroCardIdInp) {
    this->balanceInp = balanceInp;
    this->metroCardIdInp = metroCardIdInp;
}

void BalanceCommand::execute() {
    MetroCard* metroCard = MetroCard::getInstance(this->metroCardIdInp);
    metroCard->setBalance(stod(this->balanceInp));
}
