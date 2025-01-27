//
// Created by Ömer Can Baykara on 26.01.2025.
//

#ifndef COUNTER_H
#define COUNTER_H

#include <set>
#include <map>
#include <optional>
#include <vector>
#include <string>

class Counter
{
public:
    Counter(const std::set<char> &flags);

    std::map<char, int> getTotalStats();
    std::vector<std::map<char, int>> getAllStats();

    void countStream(std::istream &textStream);

    void processStream(std::istream &stream);

private:
    std::set<char> flags;

    std::vector<std::map<char, int>> allStats;
    std::map<char, int> totalStats;

    void processLine(const std::string &line, std::map<char, int> &stats);
};


#endif //COUNTER_H
