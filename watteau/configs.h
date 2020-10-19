#pragma once
#include <vector>
#include "types.h"

namespace watteau {

struct Channel {
    Index sampleCount;
    GPIOSet pins;

    void setPinMode(int mode) {
        auto p = pins;
        for (auto i = 0; p && i < 32; ++i) {
            if (p & 1)
                pinMode(i, mode);
        }
    }
};

struct Config {
    Milliseconds delayTime;

    Channel analog;
    Channel digital;
    Channel pump;

    void setPinMode() {
        analog.setPinMode(INPUT);
        digital.setPinMode(INPUT);
        pump.setPinMode(OUTPUT);
    }
};

}  // watteau
