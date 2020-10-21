#pragma once
#include <vector>
#include "types.h"
#include "log.h"

namespace watteau {

struct Channel {
    Index sampleCount;
    GPIOSet pins;

    PinCount setPinMode(int mode) {
        PinCount count = 0;
        auto p = pins;
        for (auto i = 0; p && i < 32; ++i) {
            if (p & 1) {
                info("Setting pin", i, "to", mode);
                pinMode(i, mode);
                count += 1;
            }
            return count;
        }
    }
};

struct Config {
    Milliseconds delayTime;

    Channel analog;
    Channel digital;
    Channel pump;

    void setPinMode() {
        info("analog pin count:", analog.setPinMode(INPUT));
        info("digital pin count:", digital.setPinMode(INPUT));
        info("pump pin count:", digital.setPinMode(OUTPUT));
    }
};

}  // watteau
