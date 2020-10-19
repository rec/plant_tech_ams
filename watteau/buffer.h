#pragma once

#include <vector>
#include "types.h"

namespace watteau {

template <typename Value>
struct Buffer : std::vector<Value> {
    Index index = 0;
    Index loops = 0;

    Value& top() {
        return (*this)[index];
    }

    void increment() {
        if (++index >= this->size()) {
            index = 0;
            loops += 1;
        }
    }
};

struct BitBuffer : Buffer<Byte> {
    Byte bit = 0x80;

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
        top() = isRunning ? (index | Bits::sign) : (index & Bits::body);
        increment();
    }
};

}  // watteau
