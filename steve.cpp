// steve.cpp

#include "steve.hpp"

size_t strlenUtf8(std::string_view s) {
    size_t count = 0;
    for (unsigned char c : s)
        count += (c & 0xC0) != 0x80;
    return count;
}
