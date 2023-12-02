cmake_minimum_required(VERSION 3.26)
project(aoc2023)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc2023 main.cpp
        solutions/day1/day1.cpp
        solutions/day1/day1.h
        solutions/day2/day2.cpp
        solutions/day2/day2.h)
