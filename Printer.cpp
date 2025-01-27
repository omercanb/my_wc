//
// Created by Ömer Can Baykara on 26.01.2025.
//

#include "Printer.h"
#include "Flags.h"

#include <iostream>
#include <string>
#include <map>

namespace Printer
{
    void printStats(const std::map<char, int> &stats)
    {
        _printStatsWithoutNewline(stats);
        std::cout << '\n';
    }

    void printStats(const std::map<char, int> &stats, const std::string &name)
    {
        _printStatsWithoutNewline(stats);
        std::cout << name << '\n';
    }


    void _printStatsWithoutNewline(const std::map<char, int> &stats)
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
