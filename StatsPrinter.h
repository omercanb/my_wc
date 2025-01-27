//
// Created by Ömer Can Baykara on 26.01.2025.
//

#ifndef PRINTER_H
#define PRINTER_H

#include <map>

namespace StatsPrinter
{
    void print(const std::map<char, int> &stats);
    void printWithName(const std::map<char, int> &stats, const std::string &name);
    void _printWithoutNewline(const std::map<char, int> &stats);
}


#endif //PRINTER_H
