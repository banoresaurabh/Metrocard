#ifndef METROCARD_CHECKINCOMMAND_H
#define METROCARD_CHECKINCOMMAND_H

#include "ICommand.h"

class CheckInCommand : public ICommand {
    std::string passengerCategoryInp;
    std::string fromStationInp;
    std::string metroCardIdInp;
public:
    CheckInCommand(std::string &passengerCategoryInp, std::string &fromStationInp, std::string &metroCardInp);
    void execute() override;
};


#endif //METROCARD_CHECKINCOMMAND_H
