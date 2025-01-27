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

    std::map<char, int> getTotalStats() const;
    std::vector<std::map<char, int>> getProcessedStreamStats() const;

    void process(std::istream &stream);

    void addToTotal(const std::map<char, int> &stats);

private:
    std::set<char> flags;

    std::vector<std::map<char, int>> processedStreamStats;
    std::map<char, int> totalStats;

    void accumulateStats(std::istream &stream, std::map<char, int> &stats) const;
    void cleanStats(std::map<char, int> &stats) const;

};


#endif //COUNTER_H
