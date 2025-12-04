CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = main.cpp \
      order.cpp \
      orderbook.cpp \
      matchingengine.cpp \
      dashboard.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = orderbook_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)