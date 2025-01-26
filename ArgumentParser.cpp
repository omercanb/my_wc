//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "ArgumentParser.h"

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <unordered_map>


ArgumentParser::ArgumentParser(const std::vector<std::string> &args) : args(args) {}


void ArgumentParser::addFlag(char flag)
{
    flags.insert(flag);
}


bool ArgumentParser::hasFlag(char flag)
{
    return flags.contains(flag);
}


std::set<char> ArgumentParser::getFlags()
{
    return flags;
}


std::vector<std::string> ArgumentParser::getFilepaths()
{
    return filepaths;
}


// RunOptions ArgumentParser::getRunOptions()
// {
//     RunOptions runOptions;
//
//     bool runOptionsIsEmpty = true;
//     for (int i = 1; i < args.size() - 1; i++)
//     {
//         std::string& arg = args[i];
//         if (arg[0] == '-')
//         {
//             std::set<RunOptions::Output> flags = parseFlag(arg);
//             for (RunOptions::Output flag : flags)
//             {
//                 runOptions.addOutputOption(flag);
//                 runOptionsIsEmpty = false;
//             }
//         }
//     }
//
//     if (runOptionsIsEmpty)
//     {
//         runOptions.addOutputOption(RunOptions::LINE);
//         runOptions.addOutputOption(RunOptions::WORD);
//         runOptions.addOutputOption(RunOptions::BYTE);
//     }
//     return runOptions;
// }


void ArgumentParser::parse()
{
    for (int i = 1; i < args.size(); i++)
    {
        std::string argument = args.at(i);
        if (argument[0] == '-')
        {
            parseFlag(argument);
        }
        else
        {
            parseFilepath(argument);
        }
    }
}


void ArgumentParser::parseFlag(const std::string &flag)
{
    for (char c : flag.substr(1))
    {
        if (flags.contains(c))
        {
            flags.insert(c);
        }
    }
}


void ArgumentParser::parseFilepath(const std::string &filepath)
{
    std::ifstream file(filepath);
    if (file.is_open())
    {
        filepaths.push_back(filepath);
        file.close();
    }
}

//
// ProgramInput *ArgumentParser::getProgramInput()
// {
//     enum InputType {FILE, FILES, STDIN, PIPE};
//
//     InputType type = STDIN;
//
//     RunOptions options = getRunOptions();
//
//     if (!isatty(fileno(stdin)))
//     {
//         type = PIPE;
//         return new StdinInput(options);
//     }
//
//     std::vector<std::string> files;
//     for (int i = args.size() - 1; i > 0; i--)
//     {
//         std::ifstream file(args[i]);
//
//         if (file.is_open())
//         {
//             files.push_back(args[i]);
//             if (type == FILE)
//             {
//                 type = FILES;
//             } else
//             {
//                 type = FILE;
//             }
//             file.close();
//         } else
//         {
//             break;
//         }
//     }
//
//     if (files.size() == 1)
//     {
//         return (new SingleFileInput(options, files[0]));
//     } else if (files.size() > 1)
//     {
//         return (new MultipleFileInput(options, files));
//     }
//
//     type = STDIN;
//     return new StdinInput(options);
// }
