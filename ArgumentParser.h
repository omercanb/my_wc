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

    void addValidFlag(char flag);

    bool isFlagUsed(char flag) const;

    std::set<char> getUsedFlags() const;

    std::vector<std::string> getValidInputFilepaths() const;
    std::vector<std::string> getInputFilepaths() const;


    void parse();

private:
    std::vector<std::string> args;
    std::vector<std::string> inputFilepaths;
    std::vector<std::string> validInputFilepaths;
    std::set<char> usedFlags;
    std::set<char> validFlags;

    void parseFlag(const std::string &flag);

    void parseFilepath(const std::string &filepath);
};


#endif //ARGUMENTPARSER_H
