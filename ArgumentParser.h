//
// Created by Ömer Can Baykara on 19.01.2025.
//

#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <set>
#include <vector>
#include <string>

class ArgumentParser
{
public:
    ArgumentParser(int argc, char *argv[]);

    void addFlag(char flag);

    bool hasFlag(char flag) const;

    std::set<char> getFlags();

    std::vector<std::string> getFilepaths();

    void parse();

private:
    std::vector<std::string> args;
    std::vector<std::string> filepaths;
    std::set<char> flags;
    std::set<char> validFlags;

    void parseFlag(const std::string &flag);

    void parseFilepath(const std::string &filepath);
};


#endif //ARGUMENTPARSER_H
