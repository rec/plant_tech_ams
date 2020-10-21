#pragma once
#include <vector>
#include "accumulators.h"
#include "buffer.h"
#include "config.h"
#include "types.h"

namespace watteau {

class Project {
  public:
    explicit Project(const Config& config) : config_(config) {}

    void setup() {
        config.setPinMode();
    }

    void run() {
    }

  private:
    Config config_;
    Accumulators accumulators_;
    PumpState pumpState_;
};

}  // watteau
