#pragma once

#include <cstdint>
#include <vector>

namespace watteau {

using int32 = int_fast32_t;
using int16 = int_fast16_t;
using uint8 = uint_fast8_t;

using Index = int32;
using Milliseconds = int32;
using GPIOSet = int32;
using Analog = int16;
using Byte = uint8;

using PumpState = std::vector<bool>;

struct Bits {
    static const auto sign = 0x80000000;
    static const auto body = sign - 1;
};

}  // watteau
