cmake_minimum_required(VERSION 3.26)
project(advent24)

add_compile_options(-Wno-c23-extensions)

set(CMAKE_CXX_STANDARD 26)

add_executable(day1 solutions/day01.cpp)
add_executable(day2 solutions/day02.cpp)
add_executable(day3 solutions/day03.cpp)
add_executable(day4 solutions/day04.cpp)