//
// Created by Ömer Can Baykara on 26.01.2025.
//

#ifndef PRINTER_H
#define PRINTER_H

#include <map>

namespace Printer
{
    void printStats(const std::map<char, int> &stats);
    void printStats(const std::map<char, int> &stats, const std::string &name);
    void _printStatsWithoutNewline(const std::map<char, int> &stats);
}


#endif //PRINTER_H
