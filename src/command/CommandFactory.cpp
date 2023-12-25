#include <string>

#include "BalanceCommand.h"
#include "CheckInCommand.h"
#include "CommandFactory.h"
#include "PrintSummaryCommand.h"

ICommand *CommandFactory::createCommand(std::stringstream &commandInp) {
    std::string commandType;
    commandInp >> commandType;
    ICommand* command = nullptr;
    if (commandType == "BALANCE") {
        std::string balance, metroCardId;
        commandInp >> metroCardId >> balance;
        command = new BalanceCommand(balance, metroCardId);
    } else if (commandType == "CHECK_IN") {
        std::string passengerCategory, fromStation, metroCardId;
        commandInp >> metroCardId >> passengerCategory >> fromStation;
        command = new CheckInCommand(passengerCategory, fromStation, metroCardId);
    } else if (commandType == "PRINT_SUMMARY") {
        command = new PrintSummaryCommand();
    }
    return command;
}
