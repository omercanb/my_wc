//
// Created by Ömer Can Baykara on 19.01.2025.
//

#ifndef RUNOPTIONS_H
#define RUNOPTIONS_H
#include <set>


class RunOptions {
public:
    enum Output {LINE, WORD, BYTE, CHAR};
private:
    std::set<Output> outputOptions;
public:
    RunOptions& addOption(Output option);
    bool hasOption(Output option);
    bool empty();
};



#endif //RUNOPTIONS_H
