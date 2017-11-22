cmake_minimum_required(VERSION 3.6)
project(zia)

set(CMAKE_CXX_STANDARD 14)

include_directories(API/include)

file(GLOB_RECURSE ZIA_FILES
         "API/include/*.hpp"
         "API/src/*.cpp")

add_executable(zia ${ZIA_FILES})
