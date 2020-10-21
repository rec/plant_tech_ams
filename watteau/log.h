#pragma once

#include <vector>
#include "types.h"

namespace watteau {
namespace log {

enum class Level { none, error, info, debug };

inline Level& level() {
    static Level level{info};
    return level;
}

template <typename S>
void error(S s) {
    if (level() >= Level::error)
        Serial.print(s);
}

template <typename T, typename s>
void error(S s, T t) {
    if (level() >= Level::error)
        Serial.print(s, t);
}

template <typename S>
void errorln(S s) {
    if (level() >= Level::error)
        Serial.println(s);
}

template <typename T, typename s>
void errorln(S s, T t) {
    if (level() >= Level::error)
        Serial.println(s, t);
}

template <typename S>
void info(S s) {
    if (level() >= Level::info)
        Serial.print(s);
}

template <typename T, typename s>
void info(S s, T t) {
    if (level() >= Level::info)
        Serial.print(s, t);
}

template <typename S>
void infoln(S s) {
    if (level() >= Level::info)
        Serial.println(s);
}

template <typename T, typename s>
void infoln(S s, T t) {
    if (level() >= Level::info)
        Serial.println(s, t);
}

template <typename S>
void debug(S s) {
    if (level() >= Level::debug)
        Serial.print(s);
}

template <typename T, typename s>
void debug(S s, T t) {
    if (level() >= Level::debug)
        Serial.print(s, t);
}

template <typename S>
void debugln(S s) {
    if (level() >= Level::debug)
        Serial.println(s);
}

template <typename T, typename s>
void debugln(S s, T t) {
    if (level() >= Level::debug)
        Serial.println(s, t);
}

}  // log
}  // watteau
