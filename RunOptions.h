//
// Created by Ömer Can Baykara on 19.01.2025.
//

#ifndef RUNOPTIONS_H
#define RUNOPTIONS_H

#include <set>


class RunOptions
{
public:
    enum Output { LINE, WORD, BYTE, CHAR, LONGEST};

private:
    std::set<Output> outputOptions;

public:
    RunOptions &addOutputOption(Output option);

    bool hasOutputOption(Output option) const;
};


#endif //RUNOPTIONS_H
