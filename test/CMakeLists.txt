project(test)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run passenger/PassengerTest.cpp station/StationTest.cpp)

target_link_libraries(Google_Tests_run MetroCard)
target_link_libraries(Google_Tests_run gtest gtest_main)
