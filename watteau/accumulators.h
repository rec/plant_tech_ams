#pragma once
#include <vector>
#include "types.h"

namespace watteau {

struct Accumulator {
    Index count;
    Milliseconds timeInDelay;

    void accumulate(Milliseconds delay) {
        count += 1;
        timeInDelay += delay;
    }
};

struct Accumulators {
    Accumulator all;
    std::vector<Accumulator> pumps;

    void accumulate(Milliseconds delay, const PumpState& pumpState) {
        all.accumulate(delay);

        for (auto& pump : pumps) {
            auto i = &pump - &pumps[0];
            if (pumpState[i])
                pump.accumulate(delay);
        }
    }
};

}  // watteau
