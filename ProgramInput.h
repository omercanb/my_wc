//
// Created by Ömer Can Baykara on 21.01.2025.
//

#ifndef PROGRAMINPUT_H
#define PROGRAMINPUT_H

#include <string>
#include <iostream>
#include <fstream>

#include "ProgramOutput.h"
#include "RunOptions.h"


OutputStats processInputStream(std::istream& stream, const RunOptions& options);


class ProgramInput {
public:
    virtual ProgramOutput processInput(const RunOptions &options) = 0;
    virtual ~ProgramInput() = default;
};

class SingleFileInput : public ProgramInput
{
public:
    std::string filepath;
    explicit SingleFileInput(std::string filepath) : filepath(filepath) {}
    ProgramOutput processInput(const RunOptions &options) override;
};


class MultipleFileInput : public ProgramInput
{
    public:
    std::vector<std::string> filepaths;
    explicit MultipleFileInput(const std::vector<std::string> &filepaths) : filepaths(filepaths) {}
    ProgramOutput processInput(const RunOptions &options) override;
};




#endif //PROGRAMINPUT_H
