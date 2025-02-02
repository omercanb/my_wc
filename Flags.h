//
// Created by Ömer Can Baykara on 26.01.2025.
//

#ifndef FLAGS_H
#define FLAGS_H

namespace Flags
{
    constexpr char LINE = 'l';
    constexpr char WORD = 'w';
    constexpr char BYTE = 'c';
    constexpr char CHAR = 'm';
    constexpr char LONGEST = 'L';

    inline auto VALID_FLAGS = {LINE, WORD, BYTE, CHAR, LONGEST};
}


#endif //FLAGS_H
