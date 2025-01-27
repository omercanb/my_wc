#include <iostream>
#include <fstream>
#include <vector>
#include <istream>

#include "ArgumentParser.h"
#include "StreamCounter.h"
#include "Flags.h"
#include "StatsPrinter.h"

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

    bool usesFileInput = filepaths.size() >= 1;

    StreamCounter counter(flags);
    if (!usesFileInput)
    {
        counter.process(std::cin);
    }
    else
    {
        for (const std::string &filepath : filepaths)
        {
            std::ifstream fileStream(filepath);
            counter.process(fileStream);
        }
    }

    std::vector<std::map<char, int>> allStats = counter.getProcessedStreamStats();
    if (!usesFileInput)
    {
        StatsPrinter::print(allStats[0]);
    }
    else
    {
        for (int i = 0; i < allStats.size(); i++)
        {
            StatsPrinter::printWithName(allStats[i], filepaths[i]);
        }
        if (allStats.size() > 1)
        {
            StatsPrinter::printWithName(counter.getTotalStats(), "total");
        }
    }
}