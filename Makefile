# Project Arbor makefile:

# Variables:
CXX = g++
CXXFLAGS = -Wall -Wextra -g -Iinclude
TARGET = bin/arbor.exe
SRC = $(wildcard src/*.cpp)
OBJECTS = $(SRC:.cpp=.o)

# Targets:
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

./src/%.o: ./src/%.cpp ./include/%.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: cleanall
cleanall:
	rm -f $(OBJECTS) $(TARGET)
