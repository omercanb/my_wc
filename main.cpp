#include <iostream>
#include <fstream>
#include <locale>
#include <vector>

#include "ArgumentParser.h"
#include "Counter.h"
#include "Flags.h"


int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);
    ArgumentParser parser(args);

    parser.addFlag(Flags::LINE);
    parser.addFlag(Flags::WORD);
    parser.addFlag(Flags::BYTE);
    parser.addFlag(Flags::CHAR);
    parser.addFlag(Flags::LONGEST);

    parser.parse();

    std::set<char> flags = parser.getFlags();

    std::vector<std::string> filepaths = parser.getFilepaths();

    

    std::ifstream file(filepaths.back());

    Counter counter(flags);
    counter.countStream(file);
    auto items = counter.getItems();





    std::cout << "Test";
    // std::vector<std::string> args(argv, argv + argc);
    //
    // ArgumentParser parser(args);
    // ProgramInput *programInput = parser.getProgramInput();
    // ProgramOutput out = programInput->processInput();
    // delete programInput;
    // out.print();
    // return 0;
}
