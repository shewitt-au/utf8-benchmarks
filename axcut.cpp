// axcut.cpp

#include "axcut.hpp"
#include <cmath>
#include <cstdint>

using u8 = std::uint8_t;
using u32 = std::uint32_t;

size_t utf8CharLength(u8 c) {
        if ((c & 0xFE) == 0xFC)
            return 6;
        if ((c & 0xFC) == 0xF8)
            return 5;
        if ((c & 0xF8) == 0xF0)
            return 4;
        if ((c & 0xF0) == 0xE0)
            return 3;
        if ((c & 0xE0) == 0xC0)
            return 2;
        return 1;
    }

u32 getCodePoint(std::string_view utf8Character) {
    if (utf8Character.empty())
        return 0;

    const auto firstByte = static_cast<u8>(utf8Character[0]);
    size_t charLength = utf8CharLength(firstByte);
    if (charLength > utf8Character.size())
        return 0;

    u32 codePoint = firstByte & ((1 << (8 - charLength)) - 1);
    for (size_t i = 1; i < charLength; ++i) {
        const auto byte = static_cast<u8>(utf8Character[i]);
        if ((byte & 0xC0) != 0x80)
            return 0; // Invalid continuation byte
        codePoint = (codePoint << 6) | (byte & 0x3F);
    }
    return codePoint;
}

bool isCJKGlyph(std::string_view utf8Character) {
    if (utf8Character.empty())
        return false;
    u32 codePoint = getCodePoint(utf8Character);
    return (codePoint >= 0x4E00 && codePoint <= 0x9FFF) || // CJK Unified Ideographs
            (codePoint >= 0x3400 && codePoint <= 0x4DBF) || // CJK Unified Ideographs Extension A
            (codePoint >= 0x20000 && codePoint <= 0x2A6DF) || // CJK Unified Ideographs Extension B
            (codePoint >= 0x2A700 && codePoint <= 0x2B73F) || // CJK Unified Ideographs Extension C
            (codePoint >= 0x2B740 && codePoint <= 0x2B81F) || // CJK Unified Ideographs Extension D
            (codePoint >= 0x2B820 && codePoint <= 0x2CEAF) || // CJK Unified Ideographs Extension E
            (codePoint >= 0xF900 && codePoint <= 0xFAFF) || // CJK Compatibility Ideographs
            (codePoint >= 0xAC00 && codePoint <= 0xD7A3) || // Hangul Syllables
            (codePoint >= 0x1100 && codePoint <= 0x11FF) || // Hangul Jamo
            (codePoint >= 0x3130 && codePoint <= 0x318F) || // Hangul Compatibility Jamo
            (codePoint >= 0xA960 && codePoint <= 0xA97F) || // Hangul Jamo Extended-A
            (codePoint >= 0xD7B0 && codePoint <= 0xD7FF) || // Hangul Jamo Extended-B
            (codePoint >= 0x2F800 && codePoint <= 0x2FA1F);   // CJK Compatibility Ideographs Supplement
    }

size_t utf8StringLength(const std::string_view &str) {
    if (str.empty())
        return 0;
    float count = 0;
    for (size_t idx = 0; idx < str.size(); count++) {
        std::string_view charView = str.substr(idx, utf8CharLength(str[idx]));
        if (isCJKGlyph(charView))
            count += 0.75f;

        idx += utf8CharLength(str[idx]);
    }
    return static_cast<size_t>(std::ceil(count));
}
