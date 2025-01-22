//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "ArgumentParser.h"

#include <iostream>


std::unordered_map<std::string, RunOptions::Output> argumentToEnum =
{
    {"-l", RunOptions::Output::LINE},
    {"-w", RunOptions::Output::WORD},
    {"-c", RunOptions::Output::BYTE},
    {"-m", RunOptions::Output::CHAR}
};


std::unordered_map<RunOptions::Output, std::string> enumToArgument =
{
    {RunOptions::Output::LINE, "-l"},
    {RunOptions::Output::WORD, "-w"},
    {RunOptions::Output::BYTE, "-c"},
    {RunOptions::Output::CHAR, "-m"}
};

ArgumentParser::ArgumentParser(const std::vector<std::string> &args)
{
    this->args = args;
}


RunOptions ArgumentParser::getRunOptions()
{
    RunOptions runOptions;

    runOptions.setInputType(findInputType());

    bool runOptionsIsEmpty = true;
    for (int i = 1; i < args.size() - 1; i++)
    {
        for (int outputOptionIdx = RunOptions::Output::LINE; outputOptionIdx != RunOptions::Output::CHAR; outputOptionIdx++)
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


ProgramInput* ArgumentParser::getProgramInput()
{
    RunOptions::Input type = RunOptions::Input::STDIN;

    if (!isatty(fileno(stdin)))
    {
        type = RunOptions::Input::PIPE;
    }

    std::vector<std::string> files;
    for (int i = args.size() - 1; i > 0; i --)
    {
        std::ifstream file(args[i]);

        if (file.is_open())
        {
            files.push_back(args[i]);
            if (type == RunOptions::Input::FILE)
            {
                type = RunOptions::Input::FILES;
            }
            else
            {
                type = RunOptions::Input::FILE;
            }
            file.close();
        }
        else
        {
            break;
        }
    }

    if (files.size() == 1)
    {
        return new SingleFileInput(files[0]);
    }
    else if (files.size() > 1)
    {
        return new MultipleFileInput(files);
    }

    return nullptr;
}


RunOptions::Input ArgumentParser::findInputType()
{
    RunOptions::Input type = RunOptions::Input::STDIN;

    if (!isatty(fileno(stdin)))
    {
        type = RunOptions::Input::PIPE;
    }

    for (int i = args.size() - 1; i > 0; i --)
    {
        std::ifstream file(args[i]);
        if (file.is_open())
        {
            if (type == RunOptions::Input::FILE)
            {
                type = RunOptions::Input::FILES;
                break;
            }
            else
            {
                type = RunOptions::Input::FILE;
            }
            file.close();
        }
        else
        {
            break;
        }
    }
    return type;
}