# Project Arbor raylib makefile:

# Variables:
CXX = g++
CXXFLAGS = -Wall -Wextra -g -Iinclude
TARGET = ../../bin/raylibhelloworld.exe
SRC = $(wildcard ../../raylibhelloworld.cpp)
OBJECTS = $(SRC:.c=.o)

# Targets:
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: cleanall
cleanall:
	rm -f $(OBJECTS) $(TARGET)