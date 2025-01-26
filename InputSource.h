//
// Created by Ömer Can Baykara on 26.01.2025.
//

#ifndef INPUTSOURCE_H
#define INPUTSOURCE_H
#include <istream>

#include "Counter.h"


class InputSource
{
public:
    virtual std::istream &getNextStream() = 0;

    virtual bool hasNextStream() = 0;

    virtual void addSourceInfo(CountedItem &item) = 0;

    virtual ~InputSource() = default;
};


class FileInput : public InputSource
{
private:
    ~FileInput();

    std::istream *currentStream = nullptr;
    bool readInput = false;
    std::string filepath;

public:
    explicit FileInput(std::string filepath);

    std::istream &getNextStream() override;

    void addSourceInfo(CountedItem &item) override;

    bool hasNextStream() override;
};


class MultipleFileInput : public InputSource
{
private:
    ~MultipleFileInput();

    std::istream *currentStream = nullptr;
    std::vector<std::string> filepaths;
    int idx = 0;

public:
    explicit MultipleFileInput(const std::vector<std::string> filepaths);

    std::istream &getNextStream() override;

    void addSourceInfo(CountedItem &item) override;

    bool hasNextStream() override;
};


class StdinInput : public InputSource
{
private:
    bool readInput = false;

public:
    explicit StdinInput();

    std::istream &getNextStream() override;

    void addSourceInfo(CountedItem &item) override;

    bool hasNextStream() override;
};


#endif //INPUTSOURCE_H
