// order.h
#pragma once

#include <string>

// Side of the order: buy or sell
enum class Side {
    BUY,
    SELL
};

// Represents one limit order
struct order {
    int id;             // unique id
    std::string symbol; // stock symbol, e.g. "AAPL"
    Side side;          // BUY or SELL
    double price;       // limit price
    int quantity;       // units to trade
    long long timestamp; // simple counter for time priority

    // Default constructor
    order() = default;

    // Constructor with all fields
    order(int id,
          const std::string& symbol,
          Side side,
          double price,
          int quantity,
          long long timestamp);

    // Returns "BUY" or "SELL"
    std::string sideToString() const;
};