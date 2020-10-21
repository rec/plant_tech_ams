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

template <typename T>
void print(T t) {
    Serial.print(t);
}

template <typename T, typename... Args>
void print(T t, Args... args) {
    print(t);
    print(' ');
    print(args...);
}

template <typename... Args>
void printIf(Level lev, Args... args) {
    if (level() <= lev) {
        print(args...);
        Serial.println();
    }
}

template <typename... Args>
void error(Args&&... args) {
    printIf(Level::error, args...);
}

template <typename... Args>
void info(Args&&... args) {
    printIf(Level::info, args...);
}

template <typename... Args>
void debug(Args&&... args) {
    printIf(Level::debug, args...);
}

}  // log
}  // watteau
