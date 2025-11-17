#pragma once

#include <unordered_map>
#include <string>
#include "orderbook.h"

class MatchingEngine {
public:
    MatchingEngine() = default;

    // Send a new order to the engine
    void submit(const Order& order);

    // Print only one symbol's book
    void printBook(const std::string& symbol) const;

    // Print all existing books
    void printAllBooks() const;

private:
    std::unordered_map<std::string, OrderBook> m_books;

    OrderBook& getOrCreateBook(const std::string& symbol);
};