//
// Created by Ömer Can Baykara on 19.01.2025.
//

#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include "RunOptions.h"

#include <map>


class ArgumentParser
{
public:
    explicit ArgumentParser(const std::vector<std::string> &args);

    // RunOptions getRunOptions();
    //
    // ProgramInput *getProgramInput();

    void addFlag(char flag);

    bool hasFlag(char flag);

    std::set<char> getFlags();

    std::vector<std::string> getFilepaths();

    void parse();

private:
    std::vector<std::string> args;

    std::vector<std::string> filepaths;

    void parseFlag(const std::string &flag);

    void parseFilepath(const std::string &filepath);

    std::set<char> flags;
    std::set<char> validFlags;
};


#endif //ARGUMENTPARSER_H
