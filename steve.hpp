#pragma once
// steve.hpp

#include <string_view>
#include <cassert>

namespace steve {

inline size_t utf8CodePointLength(char ch) {
    const unsigned char lead = static_cast<unsigned char>(ch);
    if ((lead & 0x80) == 0x00) return 1;
    else if ((lead & 0xE0) == 0xC0) return 2;
    else if ((lead & 0xF0) == 0xE0) return 3;
    else if ((lead & 0xF8) == 0xF0) return 4;
    else {
        assert(!"Invalid UTF-8");
        return 0;
    }
}

size_t strlenUtf8_Traditional(std::string_view s);

size_t strlenUtf8(std::string_view s);

} // namespace steve
