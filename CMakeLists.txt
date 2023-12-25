cmake_minimum_required(VERSION 3.12)
project(MetroCard)

set(CMAKE_CXX_STANDARD 20)

# List all source files in the src directory
set(SOURCE_FILES
    src/card/MetroCard.cpp
    src/passenger/Passenger.cpp
    src/station/Station.cpp
    src/util/util.cpp
    src/main.cpp
    src/command/CheckInCommand.cpp
    src/command/CommandFactory.cpp
    src/command/BalanceCommand.cpp
    src/command/PrintSummaryCommand.cpp
)

# List all header files in the src directory
set(HEADER_FILES
    src/card/MetroCard.h
    src/passenger/Passenger.h
    src/station/Station.h
    src/util/util.h
    src/constants.h
        src/command/ICommand.h
    src/command/CheckInCommand.h
    src/command/CommandFactory.h
    src/command/BalanceCommand.h
    src/command/PrintSummaryCommand.h
)

add_executable(MetroCard ${SOURCE_FILES} ${HEADER_FILES})

#add_subdirectory(test)