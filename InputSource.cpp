//
// Created by Ömer Can Baykara on 26.01.2025.
//

#include "InputSource.h"

#include <fstream>
#include <iostream>

FileInput::FileInput(std::string filepath) : filepath(filepath) {}

FileInput::~FileInput()
{
    delete currentStream;
}

std::istream &FileInput::getNextStream()
{
    currentStream = new std::ifstream(filepath);
    readInput = true;
    return *currentStream;
}

bool FileInput::hasNextStream()
{
    return !readInput;
}

void FileInput::addSourceInfo(CountedItem &item)
{
    item.name = filepath;
}

MultipleFileInput::MultipleFileInput(const std::vector<std::string> filepaths) : filepaths(filepaths){}

MultipleFileInput::~MultipleFileInput()
{
    delete currentStream;
}

std::istream &MultipleFileInput::getNextStream()
{
    currentStream = new std::ifstream(filepaths[idx++]);
    return *currentStream;
}

bool MultipleFileInput::hasNextStream()
{
    return idx < filepaths.size();
}

void MultipleFileInput::addSourceInfo(CountedItem &item)
{
    item.name = filepaths[idx - 1];
}


StdinInput::StdinInput() : InputSource() {}

std::istream &StdinInput::getNextStream()
{
    readInput = true;
    return std::cin;
}

bool StdinInput::hasNextStream()
{
    return !readInput;
}

void StdinInput::addSourceInfo(CountedItem &item)
{

}
