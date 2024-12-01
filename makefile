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
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(BIN_DIR):
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Clean up
clean:
	@echo "Cleaning up..."
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)
	@echo "Clean complete."
