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

std::string g_poemEnglish =
    "The Road Not Taken” by Robert Frost\n\n"
    "Two roads diverged in a yellow wood,\n"
    "And sorry I could not travel both\n"
    "And be one traveler, long I stood\n"
    "And looked down one as far as I could\n";

std::string g_poemChinese =
    "未选择的路 — 罗伯特·弗罗斯特\n\n"
    "黄色的树林里分出两条路，\n"
    "可惜我不能同时去涉足。\n"
    "我久久伫立，独自一人，\n"
    "尽可能地向其中一条望去。\n";

std::string g_poemRussian =
    "В жёлтом лесу расходились две дороги,\n\n"
    "И жаль, что я не мог пройти по обеим.\n"
    "Я долго стоял, одинокий путник,\n"
    "И смотрел вдаль по одной из них.\n";

std::string g_shortStringEnglish = "Short string";
std::string g_shortStringChinese = "短字符串";
std::string g_shortStringRussian = "короткая строка";
