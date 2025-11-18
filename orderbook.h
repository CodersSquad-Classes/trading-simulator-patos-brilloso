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

    void addOrder(const Order& order);

    void printSimple() const;

    std::string getSymbol() const;

    //get top N buy and sell orders (for dashboard)
    std::vector<Order> getTopBuys(int depth) const;
    std::vector<Order> getTopSells(int depth) const;

private:
    std::string m_symbol;

    std::priority_queue<Order, std::vector<Order>, BuyComparator>  m_buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellComparator> m_sellOrders;
};