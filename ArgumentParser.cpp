//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "ArgumentParser.h"

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <unordered_map>


std::unordered_map<char, RunOptions::Output> argumentToEnum =
{
    {'l', RunOptions::Output::LINE},
    {'w', RunOptions::Output::WORD},
    {'c', RunOptions::Output::BYTE},
    {'m', RunOptions::Output::CHAR},
    {'L', RunOptions::Output::LONGEST}
};


std::unordered_map<RunOptions::Output, char> enumToArgument =
{
    {RunOptions::Output::LINE, 'l'},
    {RunOptions::Output::WORD, 'w'},
    {RunOptions::Output::BYTE, 'c'},
    {RunOptions::Output::CHAR, 'm'},
    {RunOptions::Output::LONGEST,'L'}
};

ArgumentParser::ArgumentParser(const std::vector<std::string> &args) : args(args) {}


RunOptions ArgumentParser::getRunOptions()
{
    RunOptions runOptions;

    bool runOptionsIsEmpty = true;
    bool onFlag = false;
    for (int i = 1; i < args.size() - 1; i++)
    {
        std::string& arg = args[i];
        if (arg[0] == '-')
        {
            std::set<RunOptions::Output> flags = parseFlag(arg);
            for (RunOptions::Output flag : flags)
            {
                runOptions.addOutputOption(flag);
                runOptionsIsEmpty = false;
            }
        }
    }

    if (runOptionsIsEmpty)
    {
        runOptions.addOutputOption(RunOptions::LINE);
        runOptions.addOutputOption(RunOptions::WORD);
        runOptions.addOutputOption(RunOptions::BYTE);
    }
    return runOptions;
}


std::set<RunOptions::Output> ArgumentParser::parseFlag(const std::string &flag)
{
    std::set<RunOptions::Output> flags;
    for (char c : flag)
    {
        if (c == '-')
        {
            continue;
        }
        flags.insert(argumentToEnum[c]);
    }
    return flags;
}


ProgramInput *ArgumentParser::getProgramInput()
{
    enum InputType {FILE, FILES, STDIN, PIPE};

    InputType type = STDIN;

    RunOptions options = getRunOptions();

    if (!isatty(fileno(stdin)))
    {
        type = PIPE;
        return new StdinInput(options);
    }

    std::vector<std::string> files;
    for (int i = args.size() - 1; i > 0; i--)
    {
        std::ifstream file(args[i]);

        if (file.is_open())
        {
            files.push_back(args[i]);
            if (type == FILE)
            {
                type = FILES;
            } else
            {
                type = FILE;
            }
            file.close();
        } else
        {
            break;
        }
    }

    if (files.size() == 1)
    {
        return (new SingleFileInput(options, files[0]));
    } else if (files.size() > 1)
    {
        return (new MultipleFileInput(options, files));
    }

    type = STDIN;
    return new StdinInput(options);
}
