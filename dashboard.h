#pragma once

#include "matchingengine.h"

// Simple terminal colors
#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"  // BUY
#define COLOR_RED     "\033[31m"  // SELL
#define COLOR_YELLOW  "\033[33m"  // headers

// Dashboard prints the state of all order books
class Dashboard {
public:
    // depthPerSide: how many levels we want to show for buys and sells
    void render(const MatchingEngine& engine, int depthPerSide) const;
};
