//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "ArgumentParser.h"

#include <fstream>

ArgumentParser::ArgumentParser(int argc, char *argv[]) : args(argv, argv + argc) {}

void ArgumentParser::addValidFlag(char flag)
{
    validFlags.insert(flag);
}


bool ArgumentParser::isFlagUsed(char flag) const
{
    return usedFlags.contains(flag);
}


std::set<char> ArgumentParser::getFlags() const
{
    return usedFlags;
}


std::vector<std::string> ArgumentParser::getFilepaths() const
{
    return filepaths;
}


void ArgumentParser::parse()
{
    for (int i = 1; i < args.size(); i++)
    {
        std::string argument = args.at(i);
        if (argument[0] == '-')
        {
            parseFlag(argument);
        } else
        {
            parseFilepath(argument);
        }
    }
}


void ArgumentParser::parseFlag(const std::string &flag)
{
    for (char c: flag.substr(1))
    {
        if (validFlags.contains(c))
        {
            usedFlags.insert(c);
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