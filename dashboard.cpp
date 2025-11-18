#include "dashboard.h"
#include <iostream>
#include <iomanip>

void Dashboard::render(const MatchingEngine& engine, int depthPerSide) const {
    const auto& books = engine.getBooks();

    if (books.empty()) {
        std::cout << "No books to display.\n";
        return;
    }

    // Clear screen
    std::cout << "\033[2J\033[H";

    for (const auto& pair : books) {
        const OrderBook& book = pair.second;

        std::cout << COLOR_YELLOW
                  << "===== ORDER BOOK: " << book.getSymbol()
                  << " =====" << COLOR_RESET << "\n";

        // Get top buys and sells
        auto topBuys  = book.getTopBuys(depthPerSide);
        auto topSells = book.getTopSells(depthPerSide);

        // Header
        std::cout << std::left
                  << COLOR_GREEN << std::setw(20) << "BUY (price x qty)"
                  << COLOR_RED   << std::setw(20) << "SELL (price x qty)"
                  << COLOR_RESET << "\n";

        int maxRows = static_cast<int>(std::max(topBuys.size(), topSells.size()));

        for (int i = 0; i < maxRows; ++i) {
            // BUY column
            if (i < static_cast<int>(topBuys.size())) {
                const Order& b = topBuys[i];
                std::cout << COLOR_GREEN
                          << std::setw(9) << b.price
                          << " x "
                          << std::setw(6) << b.quantity
                          << COLOR_RESET;
            } else {
                std::cout << std::setw(20) << " ";
            }

            // space between columns
            std::cout << "   ";

            // SELL column
            if (i < static_cast<int>(topSells.size())) {
                const Order& s = topSells[i];
                std::cout << COLOR_RED
                          << std::setw(9) << s.price
                          << " x "
                          << std::setw(6) << s.quantity
                          << COLOR_RESET;
            }

            std::cout << "\n";
        }

        std::cout << "\n";
    }
}