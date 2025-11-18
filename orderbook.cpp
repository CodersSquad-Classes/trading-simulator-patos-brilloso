#include "orderbook.h"
#include <iostream>

OrderBook::OrderBook(const std::string& symbol)
    : m_symbol(symbol)
{
}

void OrderBook::addOrder(const Order& order) {
    if (order.side == Side::BUY) {
        m_buyOrders.push(order);
    } else {
        m_sellOrders.push(order);
    }
}

void OrderBook::printSimple() const {
    std::cout << "OrderBook for symbol: " << m_symbol << "\n";

    if (!m_buyOrders.empty()) {
        const Order& topBuy = m_buyOrders.top();
        std::cout << "Top BUY: "
                  << topBuy.price << " x " << topBuy.quantity
                  << " (ts=" << topBuy.timestamp << ")\n";
    } else {
        std::cout << "No BUY orders.\n";
    }

    if (!m_sellOrders.empty()) {
        const Order& topSell = m_sellOrders.top();
        std::cout << "Top SELL: "
                  << topSell.price << " x " << topSell.quantity
                  << " (ts=" << topSell.timestamp << ")\n";
    } else {
        std::cout << "No SELL orders.\n";
    }

    std::cout << "--------------------------\n";
}

std::string OrderBook::getSymbol() const {
    return m_symbol;
}
std::vector<Order> OrderBook::getTopBuys(int depth) const {
    std::vector<Order> result;
    if (depth <= 0) return result;

    auto copy = m_buyOrders; // copy so we do NOT modify the real book

    int count = 0;
    while (!copy.empty() && count < depth) {
        result.push_back(copy.top());
        copy.pop();
        count++;
    }
    return result;
}

std::vector<Order> OrderBook::getTopSells(int depth) const {
    std::vector<Order> result;
    if (depth <= 0) return result;

    auto copy = m_sellOrders;

    int count = 0;
    while (!copy.empty() && count < depth) {
        result.push_back(copy.top());
        copy.pop();
        count++;
    }
    return result;
}