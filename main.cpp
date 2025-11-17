#include <iostream>
#include "order.h"
#include "matchingengine.h"

int main() {
    MatchingEngine engine;
    long long ts = 0;

    // Some AAPL orders
    Order o1(1, "AAPL", Side::BUY, 100.0, 50, ts++);
    Order o2(2, "AAPL", Side::BUY, 101.0, 30, ts++);
    Order o3(3, "AAPL", Side::SELL, 105.0, 20, ts++);

    // Some MSFT orders
    Order o4(4, "MSFT", Side::SELL, 250.0, 40, ts++);
    Order o5(5, "MSFT", Side::BUY, 245.0, 10, ts++);

    engine.submit(o1);
    engine.submit(o2);
    engine.submit(o3);
    engine.submit(o4);
    engine.submit(o5);

    std::cout << "=== AAPL book ===\n";
    engine.printBook("AAPL");

    std::cout << "=== All books ===\n";
    engine.printAllBooks();

    return 0;
}