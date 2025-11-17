#pragma once

#include <string>

// Side of the order: buy or sell
enum class Side {
    BUY,
    SELL
};

// Represents one limit order
struct Order {
    int id;             // unique id
    std::string symbol; // stock symbol, e.g. "AAPL"
    Side side;          // BUY or SELL
    double price;       // limit price
    int quantity;       // units to trade
    long long timestamp; // simple counter for time priority

    Order() = default;

    Order(int id,
          const std::string& symbol,
          Side side,
          double price,
          int quantity,
          long long timestamp);

    std::string sideToString() const;
};