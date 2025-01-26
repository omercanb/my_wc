//
// Created by Ömer Can Baykara on 26.01.2025.
//



#include <istream>

#include "Counter.h"
#include "Flags.h"

// Counts::Counts(std::set<char> flags)
// {
//     if (flags.contains(Flags::LINE))
//     {
//         lines = 0;
//     }
//     if (flags.contains(Flags::WORD))
//     {
//         words = 0;
//     }
//     if (flags.contains(Flags::BYTE))
//     {
//         bytes = 0;
//     }
//     if (flags.contains(Flags::CHAR))
//     {
//         chars = 0;
//     }
//     if (flags.contains(Flags::LONGEST))
//     {
//         longestLineLength = 0;
//     }
//
//     if (chars.has_value() && bytes.has_value())
//     {
//         bytes.reset();
//     }
//
// }




CountedItem::CountedItem(const std::set<char>& flags)
{
    for (char flag : flags)
    {
        counts[flag] = 0;
    }
}


void CountedItem::add(const CountedItem &other)
{
    for (auto &[key, value] : counts)
    {
        counts[key] += other.counts.at(key);
    }
}


Counter::Counter(const std::set<char>& flags) : flags(flags), total(flags)
{
    total.name = "total";
}


std::vector<CountedItem> Counter::getItems()
{
    return items;
}

CountedItem & Counter::getNewestItem()
{
    return items.back();
}

void Counter::countStream(std::istream &textStream)
{
    items.push_back(CountedItem(flags));
    CountedItem &item = items.back();
    std::map<char, int> &counts = item.counts;

    int currentLineLength = 0;
    bool readingAWord = false;
    char c;

    while (textStream.get(c))
    {
        counts[Flags::BYTE]++;

        if (flags.contains(Flags::CHAR))
        {
            if ((c & 0xc0) != 0x80) // https://stackoverflow.com/questions/3586923/counting-unicode-characters-in-c
            {
                counts[Flags::CHAR]++;
                currentLineLength++;
            }
        }
        else
        {
            currentLineLength++;
        }

        if (c == '\n')
        {
            counts[Flags::LINE]++;

            int realLength = currentLineLength - 1;
            if (flags.contains(Flags::LONGEST) && (realLength > counts[Flags::LONGEST]))
            {
                counts[Flags::LONGEST] = realLength;
            }

            currentLineLength = 0;
        }


        if (std::isspace(c))
        {
            if (readingAWord)
            {
                counts[Flags::WORD]++;
                readingAWord = false;
            }
        }
        else
        {
            readingAWord = true;
        }

    }

    if (readingAWord)
    {
        counts[Flags::WORD]++;
    }


    total.add(item);
}
