# Path to libcurl directory
path := C:/libcurl

# C++ compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++17 -Wall


# Check for Windows operating system
ifeq ($(OS),Windows_NT)
    # On Windows, add -I and -L flags for libcurl
    CXXFLAGS += -I$(path)/include
    LIBS += LIBS := -L$(path)/lib -lcurl -lws2_32
    # Set clean command
    CLEAN_COMMAND := del
else
    # On non-Windows systems, assume libcurl is available system-wide
    LIBS += -lcurl
    # Set clean command
    CLEAN_COMMAND := rm -f
endif

# Source files
SRC := resources/Game.cpp resources/GameHandler.cpp resources/MainProgram.cpp client.cpp

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
