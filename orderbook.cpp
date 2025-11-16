#include "orderBook.h"
#include <iostream>

// Constructor
orderBook::orderBook(const std::string& symbol)
    : m_symbol(symbol)
{
}

// For now, just store the order in the correct side
// Later we will add the matching logic here
void orderBook::addorder(const order& order) {
    if (order.side == Side::BUY) {
        m_buyorders.push(order);
    } else {
        m_sellorders.push(order);
    }
}

// Very simple print: just show sizes and top orders (if any)
void orderBook::printSimple() const {
    std::cout << "orderBook for symbol: " << m_symbol << "\n";

    if (!m_buyorders.empty()) {
        const order& topBuy = m_buyorders.top();
        std::cout << "Top BUY: "
                  << topBuy.price << " x " << topBuy.quantity
                  << " (ts=" << topBuy.timestamp << ")\n";
    } else {
        std::cout << "No BUY orders.\n";
    }

    if (!m_sellorders.empty()) {
        const order& topSell = m_sellorders.top();
        std::cout << "Top SELL: "
                  << topSell.price << " x " << topSell.quantity
                  << " (ts=" << topSell.timestamp << ")\n";
    } else {
        std::cout << "No SELL orders.\n";
    }

    std::cout << "--------------------------\n";
}

std::string orderBook::getSymbol() const {
    return m_symbol;
}