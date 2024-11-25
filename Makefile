# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

# Directories for SDL2 includes and libraries
SDL2_INCLUDE = /opt/homebrew/include/SDL2
SDL2_LIB = /opt/homebrew/lib

# Target executable
TARGET = sokoban

# Source files
SRC = src/main.cpp

# Object files
OBJ = main.o

# Libraries to link
LIBS = -lSDL2

# Default rule to build the target
all: $(TARGET)

# Rule to link the object files and create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) -I$(SDL2_INCLUDE) -L$(SDL2_LIB) $(LIBS)

# Rule to compile the source files into object files
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -I$(SDL2_INCLUDE)

# Clean up object and executable files
clean:
	rm -f $(OBJ) $(TARGET)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)
