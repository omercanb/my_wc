//
// Created by Ömer Can Baykara on 19.01.2025.
//

#ifndef RUNOPTIONS_H
#define RUNOPTIONS_H

#include <set>


class RunOptions
{
public:
    enum Output {LINE, WORD, BYTE, CHAR};
    enum Input {FILE, FILES, PIPE, STDIN};
private:
    std::set<Output> outputOptions;
    Input inputOption;
public:
    RunOptions& addOutputOption(Output option);
    RunOptions& setInputType(Input option);

    bool hasOutputOption(Output option) const;
    Input getInputType() const;
};


#endif //RUNOPTIONS_H