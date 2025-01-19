# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++23 -I/opt/homebrew/include -Isrc/headers
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system
DEVFLAGS = -DDEBUG

# Directories
SRC_DIR = src
BIN_DIR = bin

# Sources and objects
MAIN_SRC = main.cpp  # Ensure main.cpp is included
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(MAIN_SRC)
OBJECTS = $(patsubst %.cpp, $(BIN_DIR)/%.o, $(notdir $(SOURCES)))

# Target executable
TARGET = $(BIN_DIR)/game

# Default rule to build the target
all: $(TARGET)

# Rule to link the target executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Rule to compile each .cpp file to .o object files in bin/
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile main.cpp to its object file in bin/
$(BIN_DIR)/main.o: main.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BIN_DIR)/main.o

# Run target to execute the game after building
run: all
	./$(TARGET)

# Dev rule to add extra compiler flags
dev: CXXFLAGS += $(DEVFLAGS)
dev: all
	./$(TARGET)

# Clean rule to remove compiled files
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: all clean
