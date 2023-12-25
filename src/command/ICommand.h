#ifndef METROCARD_ICOMMAND_H
#define METROCARD_ICOMMAND_H

#include <string>

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

#endif //METROCARD_ICOMMAND_H
