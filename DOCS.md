This projects tends ti implement a simplified version of Limit Order Book and a matching engine, similar to those used in real life financial exchanges.
First of all, a Limit Order Book is the core data structure used by many modern financial exchanges to organize and prioritize buy and sell orders. This structure tends to ensure fairness, transparency and efficiency in trading systems.
The goal for this project was being able to organize orders, priorize them correctly, displaying order book states and preparing structures for future matching logic. 
The flow we implemented asks the user for an order through the menu in main.cpp, then sends the order to the matching engine, where the engine tries to find or create the correct order book for that symbol. Then, the order is inserted into one of the BUY or SELL priority queues, and finally, the dashboard and print functions allow the inspection of the current state. 
Our classes include Order, which has the following attributes and methods:
-int id - its unique identifier
-string symbol - stock symbol
-side - Buy or sell
-double price - limit price
-int quantity - number of shares
-long long timestamp - for FIFO priority at equal prices
*sidetostring() - converts BUY/SELL to text
The we have OrderBook which represents all orders dor one stock symbol. It uses two priority queues, the buy orders, which give the gigher price first the earlier timestamp in case of tie. And the sell queue which give the lower price first th earlier timestamp in case of tie. It´s methods are the following:
*addOrder - stores the order
*printSimple - prints top BUY and SELL
*getsymbol  - returns the book symbol
Then we have the matching engine, which controls all the order books. Its meant to create or retrieve and order book for each symbol, receive new orders, direct them to the right book and provide methods to print one or all books.
And finally, we have the dashboard, which provides a formatted and user friendly overview of all order books. The dashboard displays the symbol name, the best buy price/quantity, the best sell price/quantity, and the time priority information. 
To compile and run:
*g++ -std=c++17 -o orderbook main.cpp matchingengine.cpp order.cpp orderbook.cpp dashboard.cpp
*./orderbook
conclusion and individual learnings:
Lego:
Implementing a Limit Order Book is a pretty valuable exercise for us pursuing careers associated with software development, as it exposes us to real life system design challenges. Managing data structures, priority rules and building functional interfaces. Even in this simplifies form, this project mirror the architecture and functioning of high-performance systems used in financial exchanges, giving us, students, experience with efficient algorithms, modular design and problem-solving abilities. 
Gael: