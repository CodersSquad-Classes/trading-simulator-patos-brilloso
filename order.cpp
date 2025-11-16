#include "order.h"

order::order(int id,
             const std::string& symbol,
             Side side,
             double price,
             int quantity,
             long long timestamp)
    : id(id),
      symbol(symbol),
      side(side),
      price(price),
      quantity(quantity),
      timestamp(timestamp)
{
}

std::string order::sideToString() const {
    if (side == Side::BUY) {
        return "BUY";
    } else {
        return "SELL";
    }
}