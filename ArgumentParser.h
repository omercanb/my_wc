//
// Created by Ömer Can Baykara on 19.01.2025.
//

#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include "RunOptions.h"
#include "ProgramInput.h"

#include <string>


class ArgumentParser
{
public:
    explicit ArgumentParser(const std::vector<std::string> &args);

    RunOptions getRunOptions();

    ProgramInput *getProgramInput();

private:
    std::vector<std::string> args;
};


#endif //ARGUMENTPARSER_H
