//
// Created by Ömer Can Baykara on 26.01.2025.
//

#include "StatsPrinter.h"
#include "Flags.h"

#include <iostream>
#include <string>
#include <map>

namespace StatsPrinter
{
    void print(const std::map<char, int> &stats)
    {
        _printWithoutNewline(stats);
        std::cout << '\n';
    }

    void printWithName(const std::map<char, int> &stats, const std::string &name)
    {
        _printWithoutNewline(stats);
        std::cout << name << '\n';
    }


    void _printWithoutNewline(const std::map<char, int> &stats)
    {
        std::string format = "%8d ";
        if (stats.contains(Flags::LINE))
        {
            printf(format.c_str(), stats.at(Flags::LINE));
        }
        if (stats.contains(Flags::WORD))
        {
            printf(format.c_str(), stats.at(Flags::WORD));
        }
        if (stats.contains(Flags::BYTE))
        {
            printf(format.c_str(), stats.at(Flags::BYTE));
        }
        if (stats.contains(Flags::CHAR))
        {
            printf(format.c_str(), stats.at(Flags::CHAR));
        }
        if (stats.contains(Flags::LONGEST))
        {
            printf(format.c_str(), stats.at(Flags::LONGEST));
        }
    }
}
