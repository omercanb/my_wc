cmake_minimum_required(VERSION 3.29)
project(my_wc)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_wc main.cpp
        ArgumentParser.cpp
        ArgumentParser.h
        Counter.cpp
        Counter.h
        Flags.h
        InputSource.cpp
        InputSource.h
        Printer.cpp
        Printer.h
)
