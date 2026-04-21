// steve.cpp

#include "steve.hpp"

#include <cstddef>
#include <string_view>

namespace steve {

size_t strlenUtf8_Traditional(std::string_view s) {
    size_t count = 0;
    const size_t len = s.size();
    for (int i=0; i<len;) {
        count += 1;
        i += utf8CodePointLength(s[i]);
    }
    return count;
}

size_t strlenUtf8(std::string_view s) {
    size_t count = 0;
    for (unsigned char c : s)
        count += (c & 0xC0) != 0x80;
    return count;
}

} // namespace steve
