#include <iostream>
#include "Order.h"

int main() {
    Order o1(1, "AAPL", Side::BUY, 175.50, 100, 1);
    std::cout << o1 << std::endl;
    return 0;
}