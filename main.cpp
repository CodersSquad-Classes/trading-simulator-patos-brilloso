// main.cpp
#include <iostream>
#include <string>
#include "order.h"
#include "matchingengine.h"
#include "dashboard.h"

void clearScreen() {
    std::cout << "\033[2J\033[H";
}

int main() {
    MatchingEngine engine;
    Dashboard dashboard;

    long long timestamp = 0;
    int choice;

    while (true) {
        clearScreen();
        std::cout << "\033[33m===== LIMIT ORDER BOOK — MENU =====\033[0m\n\n";
        std::cout << "1) Add Order\n";
        std::cout << "2) Show Dashboard\n";
        std::cout << "3) Show Single Order Book\n";
        std::cout << "4) Show All Order Books (simple)\n";
        std::cout << "5) Clear Screen\n";
        std::cout << "0) Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting...\n";
            break;
        }

        switch (choice) {
            case 1: {
                std::string symbol;
                int sideInput;
                double price;
                int quantity;

                std::cout << "Symbol (e.g., AAPL): ";
                std::cin >> symbol;

                std::cout << "Side (1 = BUY, 2 = SELL): ";
                std::cin >> sideInput;

                std::cout << "Price: ";
                std::cin >> price;

                std::cout << "Quantity: ";
                std::cin >> quantity;

                Side side;
                if (sideInput == 1) side = Side::BUY;
                else side = Side::SELL;

                int id = timestamp + 1;

                engine.submit(Order(id, symbol, side, price, quantity, timestamp++));
                std::cout << "\nOrder successfully added.\n";
                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }

            case 2: {
                dashboard.render(engine, 5);
                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }

            case 3: {
                std::string symbol;
                std::cout << "Symbol: ";
                std::cin >> symbol;

                engine.printBook(symbol);

                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }

            case 4: {
                engine.printAllBooks();
                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }

            case 5: {
                clearScreen();
                break;
            }

            default:
                std::cout << "Invalid option.\n";
                break;
        }
    }

    return 0;
}
