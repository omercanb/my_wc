//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "RunOptions.h"


RunOptions& RunOptions::addOutputOption(Output option)
{
    if (option == Output::CHAR)
    {
        outputOptions.erase(Output::BYTE);
        outputOptions.insert(option);
    }
    else if (option == Output::BYTE)
    {
        if (!outputOptions.contains(CHAR))
        {
            outputOptions.insert(option);
        }
    }
    else
    {
        outputOptions.emplace(option);
    }
    return *this;
}


RunOptions& RunOptions::setInputType(Input option)
{
    inputOption = option;
    return *this;
}


bool RunOptions::hasOutputOption(Output option) const
{
    return outputOptions.contains(option);
}


RunOptions::Input RunOptions::getInputType() const
{
    return inputOption;
}