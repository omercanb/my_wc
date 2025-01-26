// //
// // Created by Ömer Can Baykara on 21.01.2025.
// //
//
// #include <iostream>
// #include <string>
// #include <fstream>
// #include <sstream>
//
// #include "ProgramInput.h"
//
//
// OutputStats processInputStream(std::istream &stream, const RunOptions &options)
// {
//     int lines = 0;
//     int words = 0;
//     int bytes = 0;
//     int chars = 0;
//
//     int longestLineLength = 0;
//     int currentLineLength = 0;
//
//     const bool countLines = options.hasOutputOption(RunOptions::Output::LINE);
//     const bool countWords = options.hasOutputOption(RunOptions::Output::WORD);
//     const bool countBytes = options.hasOutputOption(RunOptions::Output::BYTE);
//     const bool countChars = options.hasOutputOption(RunOptions::Output::CHAR);
//     const bool findLongestLine = options.hasOutputOption(RunOptions::Output::LONGEST);
//
//     bool readingAWord = false;
//     char c;
//
//     while (stream.get(c))
//     {
//         if (countBytes)
//         {
//             bytes++;
//         }
//
//         if (countChars && (c & 0xc0) != 0x80)
//         // https://stackoverflow.com/questions/3586923/counting-unicode-characters-in-c
//         {
//             chars++;
//
//             if (findLongestLine)
//             {
//                 currentLineLength++;
//             }
//         }
//
//         if (findLongestLine && !countChars)
//         {
//             currentLineLength++;
//         }
//
//
//         if (c == '\n')
//         {
//             lines++;
//
//             int realLength = currentLineLength - 1;
//             if (findLongestLine && (realLength > longestLineLength))
//             {
//                 longestLineLength = realLength;
//             }
//
//             currentLineLength = 0;
//         }
//
//
//         if (countWords)
//         {
//             if (std::isspace(c))
//             {
//                 if (readingAWord)
//                 {
//                     words++;
//                     readingAWord = false;
//                 }
//             } else
//             {
//                 readingAWord = true;
//             }
//         }
//     }
//
//     if (countWords && readingAWord)
//     {
//         words++;
//     }
//
//     OutputStats stats;
//     if (options.hasOutputOption(RunOptions::WORD))
//     {
//         stats.wordCount = words;
//     }
//     if (options.hasOutputOption(RunOptions::BYTE))
//     {
//         stats.byteCount = bytes;
//     }
//     if (options.hasOutputOption(RunOptions::CHAR))
//     {
//         stats.charCount = chars;
//     }
//     if (options.hasOutputOption(RunOptions::LINE))
//     {
//         stats.lineCount = lines;
//     }
//     if (options.hasOutputOption(RunOptions::LONGEST))
//     {
//         stats.longestLineLength = longestLineLength;
//     }
//
//     return stats;
// }
//
//
// OutputStats processFile(const std::string& filepath, const RunOptions& options)
// {
//     std::ifstream infile(filepath);
//     std::istream &stream = infile;
//     OutputStats stats = processInputStream(stream, options);
//     stats.name = filepath;
//     return stats;
// }
//
//
// ProgramInput *ProgramInput::setRunOptions(const RunOptions &options)
// {
//     this->options = options;
//     return this;
// }
//
//
// ProgramInput::ProgramInput(const RunOptions &options) : options(options) {}
//
//
// SingleFileInput::SingleFileInput(const RunOptions& options, const std::string &filepath) :
// ProgramInput(options), filepath(filepath) {}
//
//
// MultipleFileInput::MultipleFileInput(const RunOptions& options, const std::vector<std::string> &filepaths) :
// ProgramInput(options), filepaths(filepaths) {}
//
//
// ProgramOutput SingleFileInput::processInput()
// {
//     return ProgramOutput().addStats(processFile(filepath, options));
// }
//
// StdinInput::StdinInput(const RunOptions& options) : ProgramInput(options){}
//
//
// ProgramOutput MultipleFileInput::processInput()
// {
//     ProgramOutput output;
//     for (auto filepath: filepaths)
//     {
//         output.addStats(processFile(filepath, options));
//     }
//     return output;
// }
//
//
// ProgramOutput StdinInput::processInput()
// {
//     std::string line;
//     std::stringstream s;
//     while (getline(std::cin, line))
//     {
//         s << line << '\n';
//     }
//     return ProgramOutput().addStats(processInputStream(s, options));
// }
