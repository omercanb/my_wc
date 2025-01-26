// //
// // Created by Ömer Can Baykara on 21.01.2025.
// //
//
// #ifndef PROGRAMINPUT_H
// #define PROGRAMINPUT_H
//
//
//
// #include "ProgramOutput.h"
// #include "RunOptions.h"
//
//
// class ProgramInput
// {
// public:
//     virtual ProgramOutput processInput() = 0;
//
//     virtual ~ProgramInput() = default;
//
//     ProgramInput *setRunOptions(const RunOptions &options);
//
// protected:
//     ProgramInput() = delete;
//     explicit ProgramInput(const RunOptions& options);
//     RunOptions options;
// };
//
// class SingleFileInput : public ProgramInput
// {
// public:
//     std::string filepath;
//
//     explicit SingleFileInput(const RunOptions& options, const std::string &filepath);
//
//     ProgramOutput processInput() override;
// };
//
// class MultipleFileInput : public ProgramInput
// {
// public:
//     std::vector<std::string> filepaths;
//
//     explicit MultipleFileInput(const RunOptions& options, const std::vector<std::string> &filepaths);
//
//     ProgramOutput processInput() override;
// };
//
//
// class StdinInput : public ProgramInput
// {
// public:
//     StdinInput(const RunOptions& options);
//
//     ProgramOutput processInput() override;
// };
//
//
// #endif //PROGRAMINPUT_H
