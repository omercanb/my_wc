#include <iostream>
#include <fstream>
#include <locale>
#include <vector>

#include "ArgumentParser.h"


int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);

    ArgumentParser parser(args);
    ProgramInput *programInput = parser.getProgramInput();
    ProgramOutput out = programInput->processInput();
    delete programInput;
    out.print();
    return 0;
}
