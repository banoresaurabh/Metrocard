#ifndef METROCARD_BALANCECOMMAND_H
#define METROCARD_BALANCECOMMAND_H

#include <string>

#include "ICommand.h"

class BalanceCommand : public ICommand {
private:
    std::string balanceInp;
    std::string metroCardIdInp;
public:
    BalanceCommand(const std::string &balanceInp, const std::string &metroCardIdInp);
    void execute() override;
};

#endif //METROCARD_BALANCECOMMAND_H
