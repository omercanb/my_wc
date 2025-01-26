//
// Created by Ömer Can Baykara on 26.01.2025.
//

#include "InputSource.h"

#include <fstream>
#include <iostream>

namespace InputSource
{

    File::File(std::string filepath) : filepath(filepath), stream(filepath) {}

    std::string File::getFilepath()
    {
        return filepath;
    }

    std::ifstream &File::getFileStream()
    {
        return stream;
    }

    FileList::FileList(std::vector<std::string> filepaths)
    {
        for (const auto& filepath : filepaths)
        {
            inputs.push_back(File(filepath));
        }
    }

    bool FileList::hasNextInput()
    {
        return idx < inputs.size();
    }

    File &FileList::getNextInput()
    {
        return inputs[idx++];
    }
};