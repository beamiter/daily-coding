cmake_minimum_required (VERSION 2.6)
project (Tutorial)

SET(CMAKE_CXX_FLAGS "-std=c++11 -o2 -g -Wall ${CMAKE_CXX_FLAGS}")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(Turorial tutorial.cpp)

