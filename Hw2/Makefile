CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = complex_sort

all: $(TARGET)

$(TARGET): main.o Complex.o Sort.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Complex.o Sort.o

main.o: main.cpp Complex.h Sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Complex.o: Complex.cpp Complex.h
	$(CXX) $(CXXFLAGS) -c Complex.cpp

Sort.o: Sort.cpp Sort.h
	$(CXX) $(CXXFLAGS) -c Sort.cpp

clean:
	rm -f *.o $(TARGET)
