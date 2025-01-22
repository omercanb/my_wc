//
// Created by Ömer Can Baykara on 19.01.2025.
//

#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include "RunOptions.h"
#include "ProgramInput.h"

#include <unistd.h>
#include <unordered_map>
#include <string>
#include <fstream>


class ArgumentParser {
public:
    ArgumentParser(const std::vector<std::string> &args);
    RunOptions getRunOptions();
    ProgramInput* getProgramInput();

private:
    std::vector<std::string> args;
    RunOptions::Input findInputType();
};



#endif //ARGUMENTPARSER_H
