//
// Created by Ömer Can Baykara on 26.01.2025.
//


#include <istream>
#include <algorithm>
#include <sstream>

#include "StreamCounter.h"
#include "Flags.h"


StreamCounter::StreamCounter(const std::set<char> &flags) : flags(flags) {}


std::map<char, int> StreamCounter::getTotalStats() const
{
    return totalStats;
}


std::vector<std::map<char, int>> StreamCounter::getProcessedStreamStats() const
{
    return processedStreamStats;
}


void StreamCounter::process(std::istream &stream)
{
    processedStreamStats.emplace_back();
    std::map<char, int> &stats = processedStreamStats.back();

    for (char flag : flags)
    {
        stats[flag];
    }

    std::string line;
    while (std::getline(stream, line))
    {
        processLine(line, stats);
    }

    std::erase_if(stats, [&](const auto &pair) {
        return !flags.contains(pair.first);
    });


    for (const auto &[key, value] : stats)
    {
        totalStats[key] += value;
    }
}


void StreamCounter::processLine(const std::string &line, std::map<char, int> &stats)
{
    stats[Flags::LINE]++;

    int lineLength;
    if (flags.contains(Flags::CHAR))
    {
        lineLength = std::count_if(line.begin(), line.end(),
        [](char c) {return (c & 0xc0) != 0x80;}); // https://stackoverflow.com/questions/3586923/counting-unicode-characters-in-c
        stats[Flags::CHAR] += lineLength + 1;
    }
    else
    {
        lineLength = line.size();
        stats[Flags::BYTE] += lineLength + 1;
    }

    if (lineLength > stats[Flags::LONGEST])
    {
        stats[Flags::LONGEST] = lineLength;
    }

    std::istringstream lineStream(line);
    const auto wordCount = std::distance(std::istream_iterator<std::string>(lineStream), {});
    stats[Flags::WORD] += wordCount;
}