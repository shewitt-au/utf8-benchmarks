// strings.cpp

#include "strings.hpp"
#include <string>
#include <random>

// Encode a single Unicode code point into UTF-8
void append_utf8(std::string& out, uint32_t cp) {
    if (cp <= 0x7F) {
        out.push_back(static_cast<char>(cp));
    } else if (cp <= 0x7FF) {
        out.push_back(static_cast<char>(0xC0 | (cp >> 6)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else if (cp <= 0xFFFF) {
        out.push_back(static_cast<char>(0xE0 | (cp >> 12)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else {
        out.push_back(static_cast<char>(0xF0 | (cp >> 18)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    }
}

std::string make_random_utf8(size_t target_bytes) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<uint32_t> dist(0, 0x10FFFF);

    std::string s;
    s.reserve(target_bytes);

    while (s.size() < target_bytes) {
        uint32_t cp = dist(rng);

        // skip surrogate range (invalid UTF-8)
        if (cp >= 0xD800 && cp <= 0xDFFF)
            continue;

        append_utf8(s, cp);
    }

    return s;
}
