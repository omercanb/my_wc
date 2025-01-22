//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "ArgumentParser.h"

#include <fstream>
#include <unistd.h>
#include <unordered_map>


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

    // runOptions.setInputType(findInputType());

    bool runOptionsIsEmpty = true;
    for (int i = 1; i < args.size() - 1; i++)
    {
        for (int outputOptionIdx = RunOptions::Output::LINE; outputOptionIdx != RunOptions::Output::CHAR;
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

    if (!isatty(fileno(stdin)))
    {
        type = PIPE;
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
        return (new SingleFileInput(files[0]))->setRunOptions(getRunOptions());
    } else if (files.size() > 1)
    {
        return (new MultipleFileInput(files))->setRunOptions(getRunOptions());
    }

    return nullptr;
}

//
// RunOptions::Input ArgumentParser::findInputType() const
// {
//     RunOptions::Input type = RunOptions::Input::STDIN;
//
//     if (!isatty(fileno(stdin)))
//     {
//         type = RunOptions::Input::PIPE;
//     }
//
//     for (int i = args.size() - 1; i > 0; i--)
//     {
//         std::ifstream file(args[i]);
//         if (file.is_open())
//         {
//             if (type == RunOptions::Input::FILE)
//             {
//                 type = RunOptions::Input::FILES;
//                 break;
//             } else
//             {
//                 type = RunOptions::Input::FILE;
//             }
//             file.close();
//         } else
//         {
//             break;
//         }
//     }
//     return type;
// }
