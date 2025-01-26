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

struct  CountedItem
{
    std::map<char, int> counts;
    std::optional<std::string> name;

    void add(const CountedItem &other);
};

class Counter
{
public:
    Counter(const std::set<char> &flags);

    std::vector<CountedItem> getItems();

    CountedItem getTotal();

    void countStream(std::istream &textStream);

    CountedItem &getNewestItem();

private:
    std::set<char> flags;

    std::vector<CountedItem> items;

    CountedItem total;

    void countLine(const std::string& line, CountedItem& item);
};


#endif //COUNTER_H
