#pragma once
#include <vector>
#include "accumulators.h"
#include "buffer.h"
#include "config.h"
#include "types.h"

namespace watteau {

class Project {
  public:
    Project(const Config& config) {
    }

    void run() {
    }

  private:
    Config config_;
    Accumulators accumulators_;
};

}  // watteau
