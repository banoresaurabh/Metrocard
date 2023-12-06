cmake_minimum_required(VERSION 3.12)
project(MetroCard)

set(CMAKE_CXX_STANDARD 14)

# List all source files in the src directory
set(SOURCE_FILES
    src/MetroCard.cpp
    src/Passenger.cpp
    src/Station.cpp
    src/util.cpp
    src/main.cpp
)

# List all header files in the src directory
set(HEADER_FILES
    src/MetroCard.h
    src/Passenger.h
    src/Station.h
    src/constants.h
    src/util.h
)

add_executable(MetroCard ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(MetroCard PRIVATE src)


