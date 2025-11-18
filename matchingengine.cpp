#include "matchingengine.h"
#include <iostream>

OrderBook& MatchingEngine::getOrCreateBook(const std::string& symbol) {
    auto it = m_books.find(symbol);

    if (it == m_books.end()) {
        auto result = m_books.emplace(symbol, OrderBook(symbol));
        return result.first->second;
    } else {
        return it->second;
    }
}

void MatchingEngine::submit(const Order& order) {
    OrderBook& book = getOrCreateBook(order.symbol);
    book.addOrder(order);
}

void MatchingEngine::printBook(const std::string& symbol) const {
    auto it = m_books.find(symbol);
    if (it == m_books.end()) {
        std::cout << "No order book for symbol: " << symbol << "\n";
    } else {
        it->second.printSimple();
    }
}

void MatchingEngine::printAllBooks() const {
    if (m_books.empty()) {
        std::cout << "No order books available.\n";
        return;
    }

    for (const auto& pair : m_books) {
        pair.second.printSimple();
    }
}
const std::unordered_map<std::string, OrderBook>& MatchingEngine::getBooks() const {
    return m_books;
}