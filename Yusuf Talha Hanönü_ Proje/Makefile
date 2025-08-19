# Makefile 

CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = Proje.cpp main.cpp AStar.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = p

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
