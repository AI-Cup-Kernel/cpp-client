# Compiler and compiler flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall
LIBS :=

# Check for Windows operating system
ifeq ($(OS),Windows_NT)
    LIBS += -lws2_32
    CLEAN_COMMAND := del
else
    CLEAN_COMMAND := rm -f
endif

# Source files
SRC := resources/Game.cpp resources/GameHandeler.cpp resources/MainProgram.cpp client.cpp

# Object files
OBJ := $(SRC:.cpp=.o)

# Target executable
TARGET := game

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	$(CLEAN_COMMAND) $(OBJ) $(TARGET)

.PHONY: all clean
