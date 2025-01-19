//
// Created by Ömer Can Baykara on 19.01.2025.
//

#include "RunOptions.h"


RunOptions& RunOptions::addOption(Output option)
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


bool RunOptions::hasOption(Output option)
{
    return outputOptions.contains(option);
}


bool RunOptions::empty()
{
    return outputOptions.empty();
}



