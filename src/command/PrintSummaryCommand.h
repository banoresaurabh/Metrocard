#ifndef METROCARD_PRINTSUMMARYCOMMAND_H
#define METROCARD_PRINTSUMMARYCOMMAND_H

#include <iostream>

#include "ICommand.h"

class PrintSummaryCommand : public ICommand {
public:
    void execute() override;
};


#endif //METROCARD_PRINTSUMMARYCOMMAND_H
