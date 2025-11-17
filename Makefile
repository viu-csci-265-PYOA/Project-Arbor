# Project Arbor makefile:

# Variables:
CXX = g++
CXXFLAGS = -Wall -Wextra -g
TARGET = /bin/Arbor
SRC = $(wildcard src/*.cpp)
OBJECTS = $(SRC:.c=.o)

# Targets:
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: cleanall
cleanall:
	rm -f $(OBJECTS) $(TARGET)


main:
	g++ src/main.cpp src/command.cpp src/action.cpp src/room.cpp -o main.exe
