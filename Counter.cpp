//
// Created by Ömer Can Baykara on 26.01.2025.
//


#include <istream>
#include <algorithm>

#include "Counter.h"

#include <sstream>

#include "Flags.h"


void CountedItem::add(const CountedItem &other)
{
    for (auto &[key, value]: counts)
    {
        counts[key] += other.counts.at(key);
    }
}


Counter::Counter(const std::set<char> &flags) : flags(flags)
{
    total.name = "total";
}


std::vector<CountedItem> Counter::getItems()
{
    return items;
}

CountedItem Counter::getTotal()
{
    return total;
}

CountedItem &Counter::getNewestItem()
{
    return items.back();
}


void Counter::countStream(std::istream &stream)
{
    items.push_back(CountedItem());
    CountedItem &item = items.back();

    bool readingAWord = false;

    std::string line;

    while (std::getline(stream, line))
    {
        item.counts[Flags::LINE]++;

        int lineLength;
        if (flags.contains(Flags::CHAR))
        {
            lineLength = std::count_if(line.begin(), line.end(),
            [](char c) {return (c & 0xc0) != 0x80;}); // https://stackoverflow.com/questions/3586923/counting-unicode-characters-in-c
            item.counts[Flags::CHAR] += lineLength + 1;
        }
        else
        {
            lineLength = line.size();
            item.counts[Flags::BYTE] += lineLength + 1;
        }

        if (lineLength > item.counts[Flags::LONGEST])
        {
            item.counts[Flags::LONGEST] = lineLength;
        }

        std::istringstream lineStream(line);
        const auto wordCount = std::distance(std::istream_iterator<std::string>(lineStream), {});
        item.counts[Flags::WORD] += wordCount;
    }

    std::erase_if(item.counts, [&](const auto &pair) {
        return !flags.contains(pair.first);
    });

    total.add(item);
}