cmake_minimum_required(VERSION 3.12)
project(MetroCard)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
    src/main.cpp
    src/lib.cpp
)

set(HEADER_FILES
    src/lib.h
)

add_executable(MetroCard ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(MetroCard PRIVATE include)


