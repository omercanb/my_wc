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
    void printCountedItem(const CountedItem &item)
    {
        std::string format = "%8d ";
        if (item.counts.contains(Flags::LINE))
        {
            printf(format.c_str(), item.counts.at(Flags::LINE));
        }
        if (item.counts.contains(Flags::WORD))
        {
            printf(format.c_str(), item.counts.at(Flags::WORD));
        }
        if (item.counts.contains(Flags::BYTE))
        {
            printf(format.c_str(), item.counts.at(Flags::BYTE));
        }
        if (item.counts.contains(Flags::CHAR))
        {
            printf(format.c_str(), item.counts.at(Flags::CHAR));
        }
        if (item.counts.contains(Flags::LONGEST))
        {
            printf(format.c_str(), item.counts.at(Flags::LONGEST));
        }
        if (item.name)
        {
            printf(item.name.value().c_str());
        }
        std::cout << std::endl;
    }
}
