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
  MKDIR = if not exist
  RMDIR = rmdir /s /q
else
  MKDIR = mkdir -p
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
	$(MKDIR) $(OBJ_DIR)

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

# Clean up
clean:
	@echo "Cleaning up..."
	$(RMDIR) $(OBJ_DIR)
	$(RMDIR) $(BIN_DIR)
	@echo "Clean complete."
