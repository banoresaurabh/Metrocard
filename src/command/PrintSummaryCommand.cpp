#include "PrintSummaryCommand.h"
#include "../station/Station.h"



void PrintSummaryCommand::execute() {
    Station* central = Station::getInstance(StationId::CENTRAL);
    Station* airport = Station::getInstance(StationId::AIRPORT);

    central->printSummary();
    airport->printSummary();
}

