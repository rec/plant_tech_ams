#pragma once
#include <cstdint>
#include <vector>

namespace watteau {

using Index = int_fast32_t;
using Analog = int_fast16_t;
using Byte = uint_fast8_t;

template <typename Value>
struct Buffer : std::vector<Value> {
    Index index = 0;
    Index loops = 0;

    Value& top() {
        return (*this)[index];
    }

    void increment() {
        if (++index >= size()) {
            index = 0;
            loops += 1;
        }
    }
};

struct BitBuffer : Buffer<Byte> {
    UByte bit = 0x80;

    void set(bool isSet) {
        if (isSet)
            top() |= bit;

        if (not (bit >>= 1)) {
            increment();
            bit = 0x80;
        }
    }
};

struct AnalogBuffer : Buffer<Analog> {
    void set(Analog value) {
        top() = value;
        increment();
    }
};

struct PumpBuffer : Buffer<Index> {
    void set(Index index, bool isRunning) {
        static const Index topBit = 0x80000000;
        static const Index bottomBits = topBit - 1;

        top() = isRunning ? (index | topBit) : (index & bottomBits);
        increment();
    }
};

}  // watteau
