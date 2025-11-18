// main.cpp
#include <iostream>
#include "order.h"
#include "matchingengine.h"
#include "dashboard.h"

int main() {
    MatchingEngine engine;
    Dashboard dashboard;

    long long ts = 0;

    // Some AAPL orders
    engine.submit(Order(1, "AAPL", Side::BUY, 100.0, 50, ts++));
    engine.submit(Order(2, "AAPL", Side::BUY, 101.0, 30, ts++));
    engine.submit(Order(3, "AAPL", Side::SELL, 105.0, 20, ts++));

    // Some MSFT orders
    engine.submit(Order(4, "MSFT", Side::SELL, 250.0, 40, ts++));
    engine.submit(Order(5, "MSFT", Side::BUY, 245.0, 10, ts++));

    // Show dashboard with top 5 levels per side
    dashboard.render(engine, 5);

    return 0;
}
