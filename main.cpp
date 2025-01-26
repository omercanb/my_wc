#include <iostream>
#include <fstream>
#include <vector>
#include <istream>

#include "ArgumentParser.h"
#include "Counter.h"
#include "Flags.h"
#include "Printer.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);
    ArgumentParser parser(args);

    for (char flag : Flags::VALID_FLAGS)
    {
        parser.addFlag(flag);
    }

    parser.parse();

    std::set<char> flags = parser.getFlags();
    std::vector<std::string> filepaths = parser.getFilepaths();

    if (flags.contains(Flags::BYTE) && flags.contains(Flags::CHAR))
    {
        flags.erase(Flags::BYTE);
    }

    if (flags.empty())
    {
        flags.insert({Flags::LINE, Flags::WORD, Flags::BYTE});
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
    for (const CountedItem &item: items)
    {
        Printer::printCountedItem(item);
    }

    if (items.size() > 1)
    {
        Printer::printCountedItem(counter.getTotal());
    }
}
