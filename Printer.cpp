//
// Created by Ömer Can Baykara on 26.01.2025.
//

#include "Printer.h"

#include <iostream>

#include "Flags.h"

namespace Printer
{
    void printCountedItem(const CountedItem &item)
    {
        std::string format = "%8d ";
        std::map<char, int> counts = item.counts;
        if (counts.contains(Flags::LINE))
        {
            printf(format.c_str(), counts.at(Flags::LINE));
        }
        if (counts.contains(Flags::WORD))
        {
            printf(format.c_str(), counts.at(Flags::WORD));
        }
        if (counts.contains(Flags::BYTE))
        {
            printf(format.c_str(), counts.at(Flags::BYTE));
        }
        if (counts.contains(Flags::CHAR))
        {
            printf(format.c_str(), counts.at(Flags::CHAR));
        }
        if (counts.contains(Flags::LONGEST))
        {
            printf(format.c_str(), counts.at(Flags::LONGEST));
        }
        if (item.name)
        {
            printf(item.name.value().c_str());
        }
        std::cout << std::endl;
    }
}
