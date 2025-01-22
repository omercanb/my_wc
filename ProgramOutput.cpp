//
// Created by Ömer Can Baykara on 21.01.2025.
//

#include "ProgramOutput.h"

#include <iostream>

void ProgramOutput::print(RunOptions options)
{
    for (auto stats : allStats)
    {
        if (options.hasOutputOption(RunOptions::Output::LINE))
        {
            std::cout << stats.lineCount << ' ';
        }
        if (options.hasOutputOption(RunOptions::Output::WORD))
        {
            std::cout << stats.wordCount << ' ';
        }
        if (options.hasOutputOption(RunOptions::Output::BYTE) || options.hasOutputOption(RunOptions::Output::CHAR))
        {
            std::cout << stats.byteCount << ' ';
        }
        if (options.getInputType() == RunOptions::Input::FILE || options.getInputType() == RunOptions::Input::FILES)
        {
            std::cout << stats.filepath << ' ';
        }
        std::cout << std::endl;

    }
}

OutputStats & ProgramOutput::createNewStats()
{
    allStats.emplace_back();
    return allStats.back();
}

OutputStats & OutputStats::setWordCount(int count)
{
    wordCount = count;
    return *this;
}

OutputStats & OutputStats::setLineCount(int count)
{
    lineCount = count;
    return *this;
}

OutputStats & OutputStats::setCharCount(int count)
{
    charCount = count;
    return *this;
}

OutputStats & OutputStats::setByteCount(int count)
{
    byteCount = count;
    return *this;
}


OutputStats & OutputStats::setFilePath(std::string filepath)
{
    this->filepath = filepath;
    return *this;
}


void ProgramOutput::addStats(OutputStats stats)
{
    allStats.push_back(stats);
}
