#pragma once

#include <queue>
#include <vector>
#include <string>
#include "order.h"

// Comparator for BUY orders
//  - higher price has priority
//  - if same price, older timestamp has priority
struct BuyComparator {
    bool operator()(const Order& a, const Order& b) const {
        if (a.price == b.price) {
            return a.timestamp > b.timestamp;
        }
        return a.price < b.price;
    }
};

// Comparator for SELL orders
//  - lower price has priority
//  - if same price, older timestamp has priority
struct SellComparator {
    bool operator()(const Order& a, const Order& b) const {
        if (a.price == b.price) {
            return a.timestamp > b.timestamp;
        }
        return a.price > b.price;
    }
};

// Order book for one symbol
class OrderBook {
public:
    explicit OrderBook(const std::string& symbol);

    // Right now it only stores the order.
    // Luego le metemos matching.
    void addOrder(const Order& order);

    // Simple print to check the top buy/sell
    void printSimple() const;

    std::string getSymbol() const;

private:
    std::string m_symbol;

    std::priority_queue<Order, std::vector<Order>, BuyComparator>  m_buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellComparator> m_sellOrders;
};