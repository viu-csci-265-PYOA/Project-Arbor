# Project Arbor makefile:

# -------------------- WINDOWS COMPILATION COMMAND FOR RAYLIB
# g++ -o bin/arbor.exe src/main.cpp src/rayGameManager.cpp src/RoomManager.cpp -I include -L lib -lraylib -lgdi32 -lwinmm
#
# -------------------- LINUX COMPILATION COMMAND FOR RAYLIB
#  pretty sure this needs raylib installed, and specifically ignores the lib folder. 
#  this worked on arch linux
#  seems like it works with only -lraylib and -lGL, but works the same with everything else
#  g++ -o bin/arbor.exe src/main.cpp src/rayGameManager.cpp src/RoomManager.cpp -I include -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

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
