#pragma once

#include <unordered_map>
#include <string>
#include "orderbook.h"

class MatchingEngine {
public:
    MatchingEngine() = default;

    void submit(const Order& order);
    void printBook(const std::string& symbol) const;
    void printAllBooks() const;

    // give read-only access to all books (for dashboard)
    const std::unordered_map<std::string, OrderBook>& getBooks() const;

private:
    std::unordered_map<std::string, OrderBook> m_books;

    OrderBook& getOrCreateBook(const std::string& symbol);
};
