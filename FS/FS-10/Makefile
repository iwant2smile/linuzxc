CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17


TARGET = copy
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
