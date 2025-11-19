# Project Arbor raylib makefile:

# Variables:
CXX = g++
CXXFLAGS = -Wall -Wextra -g -Iinclude -L lib -lraylib -lgdi32 -lwinmm
TARGET = ../../bin/raylibhelloworld.exe
SRC = $(wildcard *.cpp)
OBJECTS = $(SRC:.cpp=.o)

# Targets:
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp ../../include/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: cleanall
cleanall:
	rm -f $(OBJECTS) $(TARGET)