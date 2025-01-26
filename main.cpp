#include <iostream>
#include <fstream>
#include <vector>

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


    InputSource *input;
    if (filepaths.size() == 0)
    {
        input = new StdinInput();
    } else if (filepaths.size() == 1)
    {
        input = new FileInput(filepaths.at(0));
    } else
    {
        input = new MultipleFileInput(filepaths);
    }

    Counter counter(flags);
    while (input->hasNextStream())
    {
        counter.countStream(input->getNextStream());
        input->addSourceInfo(counter.getNewestItem());
    }
    delete input;

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
