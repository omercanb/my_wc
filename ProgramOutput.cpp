//
// Created by Ömer Can Baykara on 21.01.2025.
//

#include "ProgramOutput.h"

#include <iostream>

void ProgramOutput::print()
{

    for (int i = allStats.size() - 1; i >= 0; i--)
    {
        allStats[i].print();
    }

    if (allStats.size() > 1)
    {
        getTotalStats().print();
    }
}


ProgramOutput &ProgramOutput::addStats(const OutputStats &stats)
{
    allStats.push_back(stats);
    return *this;
}


OutputStats OutputStats::combineStats(const OutputStats &other)
{
    if (lineCount)
    {
        *lineCount += *other.lineCount;
    }
    if (wordCount)
    {
        *wordCount += *other.wordCount;
    }
    if (byteCount)
    {
        *byteCount += *other.byteCount;
    }
    if (charCount)
    {
        *charCount += *other.charCount;
    }
    return *this;
}


OutputStats ProgramOutput::getTotalStats()
{
    OutputStats total = allStats[0];
    for (int i = 1; i < allStats.size(); i++)
    {
        total = total.combineStats(allStats[i]);
    }
    total.name = "total";
    return total;
}


void OutputStats::print() const
{
    std::string format = "%8d ";
    if (lineCount)
    {
        printf(format.c_str(), *lineCount);
    }
    if (wordCount)
    {
        printf(format.c_str(), *wordCount);
    }
    if (byteCount)
    {
        printf(format.c_str(), *byteCount);
    }
    if (charCount)
    {
        printf(format.c_str(), *charCount);
    }
    if (longestLineLength)
    {
        printf(format.c_str(), *longestLineLength);
    }
    if (name)
    {
        std::cout << *name << ' ';
    }
    std::cout << std::endl;
}


