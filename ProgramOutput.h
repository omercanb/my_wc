//
// Created by Ömer Can Baykara on 21.01.2025.
//

#ifndef PROGRAMOUTPUT_H
#define PROGRAMOUTPUT_H

#include <string>
#include <optional>


struct OutputStats
{
    OutputStats combineStats(const OutputStats &other);
    void print() const;
    std::optional<int> wordCount;
    std::optional<int> lineCount;
    std::optional<int> charCount;
    std::optional<int> byteCount;
    std::optional<int> longestLineLength;
    std::optional<std::string> name;
};

class ProgramOutput
{
    std::vector<OutputStats> allStats;
    OutputStats getTotalStats();
public:
    ProgramOutput &addStats(const OutputStats &stats);

    void print();
};


#endif //PROGRAMOUTPUT_H
