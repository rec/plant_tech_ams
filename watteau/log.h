#pragma once

#include <utility>
#include <vector>
#include "types.h"

namespace watteau {
namespace log {

enum class Level { none, error, info, debug };

inline Level& level() {
    static Level level{info};
    return level;
}

class Log : public Print {
  public:
    static Log error(Level::error);
    static Log info(Level::info);
    static Log debug(Level::debug);

    virtual size_t write(uint8_t ch) {
        if (level_ <= level())
            Serial.write(ch);
    }

  private:
    Log(Level level) : level_(level) {}

    Level level_;
};

template <typename... Args>
void error(Args&&... args) {
    Log::error.print(std::forward<Args>(args)...);
}

template <typename... Args>
void info(Args&&... args) {
    Log::info.print(std::forward<Args>(args)...);
}

template <typename... Args>
void debug(Args&&... args) {
    Log::debug.print(std::forward<Args>(args)...);
}

template <typename... Args>
void errorln(Args&&... args) {
    Log::error.print(std::forward<Args>(args)...);
}

template <typename... Args>
void infoln(Args&&... args) {
    Log::info.print(std::forward<Args>(args)...);
}

template <typename... Args>
void debugln(Args&&... args) {
    Log::debug.print(std::forward<Args>(args)...);
}

}  // log
}  // watteau
