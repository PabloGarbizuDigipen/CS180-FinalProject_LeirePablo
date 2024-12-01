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

# Platform-specific commands
ifeq ($(OS),Windows_NT)
  # Windows commands
  MKDIR_OBJ = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
  MKDIR_BIN = if not exist $(BIN_DIR) mkdir $(BIN_DIR)
  RMDIR = rmdir /s /q
else
  # Linux/Unix commands
  MKDIR_OBJ = mkdir -p $(OBJ_DIR)
  MKDIR_BIN = mkdir -p $(BIN_DIR)
  RMDIR = rm -rf
endif

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
	$(MKDIR_OBJ)

$(BIN_DIR):
	$(MKDIR_BIN)

# Clean up
clean:
	@echo "Cleaning up..."
	@if exist $(OBJ_DIR) $(RMDIR) $(OBJ_DIR)
	@if exist $(BIN_DIR) $(RMDIR) $(BIN_DIR)
	@echo "Clean complete."
