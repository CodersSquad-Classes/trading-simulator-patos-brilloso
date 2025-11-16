#pragma once

#include <queue>
#include <vector>
#include <string>
#include "order.h"

// Comparator for buy orders:
//  - higher price has priority
//  - if same price, older order (smaller timestamp) has priority
struct BuyComparator {
    bool operator()(const order& a, const order& b) const {
        if (a.price == b.price) {
            // we want the older order (smaller timestamp) to be on top,
            // so we return true if 'a' is newer (b should go first)
            return a.timestamp > b.timestamp;
        }
        // higher price should be on top, so we return true if 'a' has lower price
        return a.price < b.price;
    }
};

// Comparator for sell orders:
//  - lower price has priority
//  - if same price, older order (smaller timestamp) has priority
struct SellComparator {
    bool operator()(const order& a, const order& b) const {
        if (a.price == b.price) {
            return a.timestamp > b.timestamp;
        }
        // lower price should be on top, so we return true if 'a' has higher price
        return a.price > b.price;
    }
};

// Represents the order book for one stock symbol
class orderBook {
public:
    // Create an empty order book for a given symbol
    explicit orderBook(const std::string& symbol);

    // Add a new order to the book
    // Later we will make this also do the matching
    void addorder(const order& order);

    // Print a simple view of the book (for debugging)
    void printSimple() const;

    // Get stock symbol
    std::string getSymbol() const;

private:
    std::string m_symbol;

    // Priority queues for buy and sell orders
    std::priority_queue<order, std::vector<order>, BuyComparator> m_buyorders;
    std::priority_queue<order, std::vector<order>, SellComparator> m_sellorders;
};