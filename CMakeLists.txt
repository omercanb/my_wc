cmake_minimum_required(VERSION 3.29)
project(my_wc)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_wc main.cpp
        RunOptions.cpp
        RunOptions.h
        ArgumentParser.cpp
        ArgumentParser.h
        ProgramOutput.cpp
        ProgramOutput.h
        Counter.cpp
        Counter.h
        Flags.h
        InputSource.cpp
        InputSource.h
)
