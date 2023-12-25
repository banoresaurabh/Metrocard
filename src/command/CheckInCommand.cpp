#include "CheckInCommand.h"
#include "../passenger/Passenger.h"
#include "../util/util.h"

CheckInCommand::CheckInCommand(std::string &passengerCategoryInp, std::string &fromStationInp,
                               std::string &metroCardInp) {
    this->passengerCategoryInp = passengerCategoryInp;
    this->fromStationInp = fromStationInp;
    this->metroCardIdInp = metroCardInp;
}

void CheckInCommand::execute() {
    Passenger* passenger = Passenger::getInstance(this->metroCardIdInp,
                                                  getPassengerTypeEnumFromString(this->passengerCategoryInp));
    passenger->checkIn(this->metroCardIdInp, getPassengerTypeEnumFromString(this->passengerCategoryInp),
                       getStationNameEnumFromString(this->fromStationInp));
}
