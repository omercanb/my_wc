//
// Created by Ömer Can Baykara on 26.01.2025.
//

#ifndef COUNTER_H
#define COUNTER_H

#include <set>
#include <map>
#include <vector>
#include <string>

class StreamCounter
{
public:
    StreamCounter(const std::set<char> &flags);

    std::map<char, int> getTotalStats();
    std::vector<std::map<char, int>> getProcessedStreamStats();

    void process(std::istream &stream);

private:
    std::set<char> flags;

    std::vector<std::map<char, int>> processedStreamStats;
    std::map<char, int> totalStats;

    void processLine(const std::string &line, std::map<char, int> &stats);
};


#endif //COUNTER_H
