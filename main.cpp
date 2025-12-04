// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#include "order.h"
#include "matchingengine.h"
#include "dashboard.h"

// Genera un double aleatorio en [min, max]
double randomDouble(double min, double max) {
    double r = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
    return min + r * (max - min);
}

int main() {
    // Semilla aleatoria
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    MatchingEngine engine;
    Dashboard dashboard;

    long long timestamp = 0;
    int nextOrderId = 1;

    // Algunos símbolos de ejemplo
    std::vector<std::string> symbols = {"AAPL", "MSFT", "TSLA"};

    // Parámetros de la “simulación en tiempo real”
    const int ticks = 50;          // cuántas “actualizaciones” de pantalla
    const int ordersPerTick = 5;   // cuántas órdenes nuevas por actualización
    const int depthPerSide = 5;    // niveles a mostrar por lado en el libro
    const int delayMs = 500;       // milisegundos entre cada render del dashboard

    for (int t = 0; t < ticks; ++t) {
        // En cada tick generamos algunas órdenes nuevas
        for (int i = 0; i < ordersPerTick; ++i) {
            // Elegir símbolo aleatorio
            const std::string& sym = symbols[std::rand() % symbols.size()];

            // Lado aleatorio (BUY o SELL)
            Side side = (std::rand() % 2 == 0) ? Side::BUY : Side::SELL;

            // Precio base por símbolo (solo para que no se vean todos iguales)
            double basePrice = 0.0;
            if (sym == "AAPL") basePrice = 180.0;
            else if (sym == "MSFT") basePrice = 350.0;
            else if (sym == "TSLA") basePrice = 250.0;
            else basePrice = 100.0;

            // Pequeña variación aleatoria
            double price = basePrice + randomDouble(-5.0, 5.0);

            // Cantidad aleatoria entre 10 y 100
            int quantity = 10 + (std::rand() % 91);

            Order order(
                nextOrderId++,
                sym,
                side,
                price,
                quantity,
                timestamp++
            );

            engine.submit(order);
        }

        // Render del dashboard “en tiempo real”
        dashboard.render(engine, depthPerSide);

        // Pequeña pausa para que se vea el efecto de actualización
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }

    std::cout << "\n\nSimulation finished. Final snapshot of all books:\n\n";
    engine.printAllBooks();

    return 0;
}