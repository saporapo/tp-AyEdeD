CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./biblioteca

SRC = principal.cpp compresor.cpp descompresor.cpp AyEdeD-TP-K.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = huffman

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
