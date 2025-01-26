//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "ArgumentParser.h"

#include <fstream>

ArgumentParser::ArgumentParser(const std::vector<std::string> &args) : args(args)
{
}


void ArgumentParser::addFlag(char flag)
{
    validFlags.insert(flag);
}


bool ArgumentParser::hasFlag(char flag) const
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