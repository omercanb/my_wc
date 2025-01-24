//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "ArgumentParser.h"

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <unordered_map>


std::unordered_map<std::string, RunOptions::Output> argumentToEnum =
{
    {"-l", RunOptions::Output::LINE},
    {"-w", RunOptions::Output::WORD},
    {"-c", RunOptions::Output::BYTE},
    {"-m", RunOptions::Output::CHAR},
    {"-L", RunOptions::Output::LONGEST}
};


std::unordered_map<RunOptions::Output, std::string> enumToArgument =
{
    {RunOptions::Output::LINE, "-l"},
    {RunOptions::Output::WORD, "-w"},
    {RunOptions::Output::BYTE, "-c"},
    {RunOptions::Output::CHAR, "-m"},
    {RunOptions::Output::LONGEST, "-L"}
};

ArgumentParser::ArgumentParser(const std::vector<std::string> &args)
{
    this->args = args;
}


RunOptions ArgumentParser::getRunOptions()
{
    RunOptions runOptions;

    bool runOptionsIsEmpty = true;
    for (int i = 1; i < args.size() - 1; i++)
    {
        for (int outputOptionIdx = RunOptions::Output::LINE;
            outputOptionIdx <= RunOptions::Output::LONGEST;
            outputOptionIdx++)
        {
            RunOptions::Output option = static_cast<RunOptions::Output>(outputOptionIdx);
            if (args[i] == enumToArgument[option])
            {
                runOptionsIsEmpty = false;
                runOptions.addOutputOption(option);
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