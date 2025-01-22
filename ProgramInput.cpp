//
// Created by Ömer Can Baykara on 21.01.2025.
//

#include "ProgramInput.h"


OutputStats processInputStream(std::istream& stream, const RunOptions& options)
{
    int words = 0;
    int lines = 0;

    if (options.hasOutputOption(RunOptions::Output::WORD) || options.hasOutputOption(RunOptions::Output::LINE))
    {
        bool readingAWord = false;
        char c;

        bool looping = true;
        while (looping)
        {
            stream.get(c);
            if (stream.eof())
            {
                looping = false;
                c = ' ';
            }

            if (c == '\n')
            {
                lines++;
                if (readingAWord)
                {
                    words++;
                    readingAWord = false;
                }
            }
            else if (std::isspace(c))
            {
                if (readingAWord)
                {
                    words++;
                    readingAWord = false;
                }
            }
            else
            {
                readingAWord = true;
            }
        }
    }
    // Count chars for UTF8
    // This is supposed to be the same as bytes if there is no multi byte support on the locale
    int chars = 0;
    if (options.hasOutputOption(RunOptions::Output::CHAR) ||options.hasOutputOption(RunOptions::BYTE))
    {
        stream.clear();
        stream.seekg(0, std::ios::beg);
        char c;
        while (stream)
        {
            stream.get(c);
            if ((c & 0xc0) != 0x80) // https://stackoverflow.com/questions/3586923/counting-unicode-characters-in-c
            {
                chars ++;
            }
        }
    }


    OutputStats stats;
    if (options.hasOutputOption(RunOptions::Output::WORD))
    {
        stats.setWordCount(words);
    }
    if (options.hasOutputOption(RunOptions::Output::BYTE))
    {
        stats.setByteCount(chars);
    }
    if (options.hasOutputOption(RunOptions::Output::CHAR))
    {
        stats.setByteCount(chars);
        stats.setCharCount(chars);
    }
    if (options.hasOutputOption(RunOptions::Output::LINE))
    {
        stats.setLineCount(lines);
    }
    return stats;
}


ProgramOutput SingleFileInput::processInput(const RunOptions &options)
{
    std::ifstream infile(filepath);
    std::istream& stream = infile;
    OutputStats stats = processInputStream(stream, options);
    stats.filepath = filepath;
    ProgramOutput output;
    output.addStats(stats);
    return output;
}


ProgramOutput MultipleFileInput::processInput(const RunOptions &options)
{
    ProgramOutput output;
    for (auto filepath : filepaths)
    {
        std::ifstream infile(filepath);
        std::istream& stream = infile;
        OutputStats stats = processInputStream(stream, options);
        stats.filepath = filepath;
        output.addStats(stats);
    }
    return output;
}