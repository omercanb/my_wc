//
// Created by Ömer Can Baykara on 21.01.2025.
//

#ifndef PROGRAMOUTPUT_H
#define PROGRAMOUTPUT_H
#include <string>

#include "RunOptions.h"

class OutputStats;

class ProgramOutput {
    std::vector<OutputStats> allStats;
public:
    OutputStats& createNewStats();
    void addStats(OutputStats stats);
    void print(RunOptions options);
};

class OutputStats
{
public:
    int wordCount;
    int lineCount;
    int charCount;
    int byteCount;
    std::string filepath;
public:
    OutputStats& setWordCount(int);
    OutputStats& setLineCount(int);
    OutputStats& setCharCount(int);
    OutputStats& setByteCount(int);
    OutputStats& setFilePath(std::string);
};



#endif //PROGRAMOUTPUT_H
