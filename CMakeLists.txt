cmake_minimum_required(VERSION 3.29)
project(my_wc)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_wc main.cpp
        ArgumentParser.cpp
        ArgumentParser.h
        StreamCounter.cpp
        StreamCounter.h
        Flags.h
        StatsPrinter.cpp
        StatsPrinter.h
)
