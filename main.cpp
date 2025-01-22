#include <iostream>
#include <fstream>
#include <locale>
#include <vector>

#include "ArgumentParser.h"


int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);

    ArgumentParser parser(args);
    RunOptions runOptions = parser.getRunOptions();
    ProgramInput* programInput = parser.getProgramInput();
    ProgramOutput out = programInput->processInput(runOptions);
    delete programInput;
    out.print(runOptions);
    return 0;

    // if a file is passed always read from file
    // No args
    // if (argc == 1)
    // {
    //     std::cerr << "Invalid usage\n";
    //     return -1;
    // }
    //
    // // Parse args
    // Arguments arguments;
    //
    // RunOptions runOptions;
    // for (int i = 1; i < argc - 1; i++)
    // {
    //     if (argv[i] == arguments.LINE)
    //     {
    //         runOptions.addOutputOption(RunOptions::Output::LINE);
    //     }
    //     else if (argv[i] == arguments.CHAR)
    //     {
    //         runOptions.addOutputOption(RunOptions::Output::CHAR);
    //     }
    //     else if (argv[i] == arguments.BYTE)
    //     {
    //         runOptions.addOutputOption(RunOptions::Output::BYTE);
    //     }
    //     else if (argv[i] == arguments.WORD)
    //     {
    //         runOptions.addOutputOption(RunOptions::Output::WORD);
    //     }
    // }
    //
    // // Set default args
    // if (runOptions.empty())
    // {
    //     runOptions.addOutputOption(RunOptions::Output::WORD);
    //     runOptions.addOutputOption(RunOptions::Output::LINE);
    //     runOptions.addOutputOption(RunOptions::Output::BYTE);
    // }
    //
    //
    // // Decide on the input (file or std in)
    // std::string filepath = argv[argc-1];
    // std::ifstream infile(filepath);
    // bool usingFile = infile.is_open();
    // std::istream& file = infile.is_open() ? infile : std::cin; // file should be renamed input
    //
    //
    // std::cout << "    ";
    //
    //
    // // Count the words and lines by checking the whitespace and if we went to a word after the whitespace
    // // I feel like this has some trouble on BOW, because normally at the beginning of a file it would be at
    // // readingAWord false, but if there is BOW it becomes true. BOW is relevant for utf-8 encoded files
    //
    // int words = 0;
    // int lines = 0;
    //
    // if (runOptions.hasOutputOption(RunOptions::Output::WORD) || runOptions.hasOutputOption(RunOptions::Output::LINE))
    // {
    //     bool readingAWord = false;
    //     char c;
    //
    //     bool looping = true;
    //     while (looping)
    //     {
    //         file.get(c);
    //         if (file.eof())
    //         {
    //             looping = false;
    //             c = ' ';
    //         }
    //
    //         if (c == '\n')
    //         {
    //             lines++;
    //             if (readingAWord)
    //             {
    //                 words++;
    //                 readingAWord = false;
    //             }
    //         }
    //         else if (std::isspace(c))
    //         {
    //             if (readingAWord)
    //             {
    //                 words++;
    //                 readingAWord = false;
    //             }
    //         }
    //         else
    //         {
    //             readingAWord = true;
    //         }
    //     }
    // }
    //
    //
    // // Count chars for UTF8
    // // This is supposed to be the same as bytes if there is no multi byte support on the locale
    // int chars = 0;
    // if (runOptions.hasOutputOption(RunOptions::Output::CHAR))
    // {
    //     file.clear();
    //     file.seekg(0, std::ios::beg);
    //     char c;
    //     while (file)
    //     {
    //         file.get(c);
    //         if ((c & 0xc0) != 0x80) // https://stackoverflow.com/questions/3586923/counting-unicode-characters-in-c
    //         {
    //             chars ++;
    //         }
    //     }
    // }
    //
    //
    // if (runOptions.hasOutputOption(RunOptions::Output::LINE))
    // {
    //     std::cout << lines << ' ';
    // }
    //
    // if (runOptions.hasOutputOption(RunOptions::Output::WORD))
    // {
    //     std::cout << words << ' ';
    // }
    //
    // if (runOptions.hasOutputOption(RunOptions::Output::BYTE))
    // {
    //     std::cout << std::filesystem::file_size(filepath) << ' ';
    // }
    //
    // if (runOptions.hasOutputOption(RunOptions::Output::CHAR))
    // {
    //     std::cout << chars << ' ';
    // }
    //
    //
    // // Not needed if not using file
    // // std::string filename;
    // // size_t lastSeparator = filepath.find_last_of('/');
    // //
    // // if (lastSeparator == std::string::npos)
    // // {
    // //     filename = filepath;
    // // }
    // // else
    // // {
    // //     filename = filepath.substr(lastSeparator + 1);
    // // }
    //
    // if (usingFile)
    // {
    //     std::cout << filepath;
    // }
    //  std::cout << '\n';
    // return 0;
}
