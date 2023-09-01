path := C:/libcurl
CXX := g++
CXXFLAGS := -std=c++17 -Wall -I$(path)/include
LIBS := -lcurl -L$(path)/lib

# Check for Windows operating system
ifeq ($(OS),Windows_NT)
    LIBS += -lws2_32
    CLEAN_COMMAND := del
else
    CLEAN_COMMAND := rm -f
endif

# Source files
SRC := resources/Game.cpp resources/GameHandler.cpp resources/MainProgram.cpp client.cpp
DEPS := $(wildcard *.h) # Include all header files in the dependencies

# Object files
OBJ := $(SRC:.cpp=.o)

# Target executable
TARGET := game

# Default target
all: $(TARGET)
$(info Compiling: $(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIBS))
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

# Compile source files to object files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	$(CLEAN_COMMAND) $(OBJ) $(TARGET)

.PHONY: all clean
