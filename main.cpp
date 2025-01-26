#include <iostream>
#include <fstream>
#include <vector>
#include <istream>

#include "ArgumentParser.h"
#include "Counter.h"
#include "Flags.h"
#include "InputSource.h"
#include "Printer.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);
    ArgumentParser parser(args);

    parser.addFlag(Flags::LINE);
    parser.addFlag(Flags::WORD);
    parser.addFlag(Flags::BYTE);
    parser.addFlag(Flags::CHAR);
    parser.addFlag(Flags::LONGEST);

    parser.parse();

    std::set<char> flags = parser.getFlags();
    std::vector<std::string> filepaths = parser.getFilepaths();

    if (flags.contains(Flags::BYTE) && flags.contains(Flags::CHAR))
    {
        flags.erase(Flags::BYTE);
    }

    if (flags.empty())
    {
        flags.insert(Flags::LINE);
        flags.insert(Flags::WORD);
        flags.insert(Flags::BYTE);
    }


    Counter counter(flags);
    if (filepaths.size() == 0)
    {
        counter.countStream(std::cin);
    }
    else
    {
        for (const std::string &filepath : filepaths)
        {
            std::ifstream fileStream(filepath);
            counter.countStream(fileStream);
            counter.getNewestItem().name = filepath;
        }
    }

    std::vector<CountedItem> items = counter.getItems();
    for (CountedItem item: items)
    {
        Printer::printCountedItem(item);
    }

    if (items.size() > 1)
    {
        Printer::printCountedItem(counter.getTotal());
    }
}
