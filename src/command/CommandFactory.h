#ifndef METROCARD_COMMANDFACTORY_H
#define METROCARD_COMMANDFACTORY_H

#include <sstream>
#include <string>

#include "ICommand.h"


class CommandFactory {
public:
    ~CommandFactory() = default;
    static ICommand* createCommand(std::stringstream &commandStr);
};


#endif //METROCARD_COMMANDFACTORY_H
