# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g -std=c11 -Iinclude
LDFLAGS = -pthread

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Files
HEADERS = $(wildcard $(INC_DIR)/*.h)
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/hacker_tool.exe

# Commands
ERASE = rm -rf

# Default target
.PHONY: all clean
all: $(TARGET)

# Linking step
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	@echo "Linking executable..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build complete: $@"

# Compilation step
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Create necessary directories
$(OBJ_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

# Clean up
clean:
	@echo "Cleaning up..."
	$(ERASE) $(OBJ_DIR) $(BIN_DIR)
	@echo "Clean complete."
