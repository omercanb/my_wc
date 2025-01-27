#include <iostream>
#include <fstream>
#include <vector>
#include <istream>

#include "ArgumentParser.h"
#include "StreamCounter.h"
#include "Flags.h"
#include "StatsPrinter.h"

void addAllValidFlags(ArgumentParser &parser);
void configureFlagsForProcessing(std::set<char> &flags);
void processInputFiles(StreamCounter &counter, const std::vector<std::string> &filepaths);
void processStdinInput(StreamCounter &counter);
void printStatsForFiles(StreamCounter &counter, const std::vector<std::string> &filepaths);

int main(int argc, char *argv[])
{
    ArgumentParser parser(argc, argv);
    addAllValidFlags(parser);
    parser.parse();

    std::set<char> flagsUsed = parser.getFlags();
    std::vector<std::string> inputFilepaths = parser.getFilepaths();

    configureFlagsForProcessing(flagsUsed);

    bool useFilesAsInput = inputFilepaths.size() >= 1;

    StreamCounter counter(flagsUsed);
    if (useFilesAsInput)
    {
        processInputFiles(counter, inputFilepaths);
        printStatsForFiles(counter, inputFilepaths);
    }
    else
    {
        processStdinInput(counter);
        auto stats = counter.getProcessedStreamStats()[0];
        StatsPrinter::print(stats);
    }
}


void addAllValidFlags(ArgumentParser &parser)
{
    for (const char flag : Flags::VALID_FLAGS)
    {
        parser.addFlag(flag);
    }
}


void configureFlagsForProcessing(std::set<char> &flags)
{
    if (flags.contains(Flags::BYTE) && flags.contains(Flags::CHAR))
    {
        flags.erase(Flags::BYTE);
    }

    if (flags.empty())
    {
        flags.insert({Flags::LINE, Flags::WORD, Flags::BYTE});
    }
}


void processInputFiles(StreamCounter &counter, const std::vector<std::string> &filepaths)
{
    for (const std::string &filepath : filepaths)
    {
        std::ifstream fileStream(filepath);
        counter.process(fileStream);
    }
}


void processStdinInput(StreamCounter &counter)
{
    counter.process(std::cin);
}


void printStatsForFiles(StreamCounter &counter, const std::vector<std::string> &filepaths)
{
    const auto &fileStats = counter.getProcessedStreamStats();
    for (int i = 0; i < fileStats.size(); i++)
    {
        StatsPrinter::printWithName(fileStats[i], filepaths[i]);
    }

    if (fileStats.size() > 1)
    {
        StatsPrinter::printWithName(counter.getTotalStats(), "total");
    }
}
