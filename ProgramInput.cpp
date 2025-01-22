//
// Created by Ömer Can Baykara on 21.01.2025.
//

#include "ProgramInput.h"


OutputStats processInputStream(std::istream &stream, const RunOptions &options)
{
    int lines = 0;
    int words = 0;
    int bytes = 0;
    int chars = 0;

    const bool countLines = options.hasOutputOption(RunOptions::LINE);
    const bool countWords = options.hasOutputOption(RunOptions::WORD);
    const bool countBytes = options.hasOutputOption(RunOptions::BYTE);
    const bool countChars = options.hasOutputOption(RunOptions::CHAR);

    bool readingAWord = false;
    char c;

    while (stream.get(c))
    {
        if (countBytes)
        {
            bytes++;
        }

        if (countChars && (c & 0xc0) != 0x80)
        // https://stackoverflow.com/questions/3586923/counting-unicode-characters-in-c
        {
            chars++;
        }

        if (countLines && c == '\n')
        {
            lines++;
        }

        if (countWords)
        {
            if (std::isspace(c))
            {
                if (readingAWord)
                {
                    words++;
                    readingAWord = false;
                }
            } else
            {
                readingAWord = true;
            }
        }
    }

    if (countWords && readingAWord)
    {
        words++;
    }

    OutputStats stats;
    if (options.hasOutputOption(RunOptions::WORD))
    {
        stats.wordCount = words;
    }
    if (options.hasOutputOption(RunOptions::BYTE))
    {
        stats.byteCount = bytes;
    }
    if (options.hasOutputOption(RunOptions::CHAR))
    {
        stats.charCount = chars;
    }
    if (options.hasOutputOption(RunOptions::LINE))
    {
        stats.lineCount = lines;
    }

    return stats;
}


OutputStats processFile(const std::string& filepath, const RunOptions& options)
{
    std::ifstream infile(filepath);
    std::istream &stream = infile;
    OutputStats stats = processInputStream(stream, options);
    stats.name = filepath;
    return stats;
}


ProgramInput *ProgramInput::setRunOptions(const RunOptions &options)
{
    this->options = options;
    return this;
}


SingleFileInput::SingleFileInput(const std::string &filepath) : filepath(filepath) {}


MultipleFileInput::MultipleFileInput(const std::vector<std::string> &filepaths) : filepaths(filepaths) {}


ProgramOutput SingleFileInput::processInput()
{
    return ProgramOutput().addStats(processFile(filepath, options));
}


ProgramOutput MultipleFileInput::processInput()
{
    ProgramOutput output;
    for (auto filepath: filepaths)
    {
        output.addStats(processFile(filepath, options));
    }
    return output;
}
