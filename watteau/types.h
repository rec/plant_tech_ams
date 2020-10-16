#pragma once

#include <cstdint>
#include <vector>

namespace watteau {

using Index = int_fast32_t;
using Milliseconds = int_fast32_t;
using Analog = int_fast16_t;
using Byte = uint_fast8_t;
using PumpState = std::vector<bool>;

}  // watteau
