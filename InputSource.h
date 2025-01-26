//
// Created by Ömer Can Baykara on 26.01.2025.
//

#ifndef INPUTSOURCE_H
#define INPUTSOURCE_H
#include <istream>
#include <fstream>

#include "Counter.h"

namespace InputSource
{
    class File
    {
    public:
        File(std::string filepath);

        std::string getFilepath();
        std::ifstream &getFileStream();
    private:
        std::string filepath;
        std::ifstream stream;
    };

    class FileList
    {
    public:
        FileList(std::vector<std::string> filepaths);
        bool hasNextInput();
        File &getNextInput();
    private:
        int idx = 0;
        std::vector<File> inputs;
    };
}

#endif //INPUTSOURCE_H
