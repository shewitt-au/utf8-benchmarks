#pragma once
// axcut.hpp

#include <string_view>
#include <cstdint>

namespace axcut {

using u8 = std::uint8_t;
using u32 = std::uint32_t;

size_t utf8StringLength(const std::string_view &str);
size_t utf8CharLength2(u8 c);
size_t utf8StringLength2(const std::string_view &str);

} // namespace axcut
