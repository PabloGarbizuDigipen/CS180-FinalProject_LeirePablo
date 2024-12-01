# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g -std=c11 -Iinclude
LDFLAGS = -pthread

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = .

# Files
HEADERS = $(wildcard $(INC_DIR)/*.h)
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = hacker_tool.exe

# Platform-specific commands
ifeq ($(OS),Windows_NT)
  # Windows commands
  MKDIR_OBJ = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
  RMDIR_OBJ = if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
  RMDIR_BIN = if exist $(TARGET) del /q $(TARGET)
else
  # Linux/Unix commands
  MKDIR_OBJ = mkdir -p $(OBJ_DIR)
  RMDIR_OBJ = rm -rf $(OBJ_DIR)
  RMDIR_BIN = rm -f $(TARGET)
endif

# Default target
.PHONY: all clean
all: $(TARGET)

# Linking step
$(TARGET): $(OBJECTS) | $(OBJ_DIR)
	@echo "Linking executable..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

# Compilation step
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Create necessary directories
$(OBJ_DIR):
	$(MKDIR_OBJ)

# Clean up
clean:
	@echo "Cleaning up..."
	$(RMDIR_OBJ)
	$(RMDIR_BIN)
	@echo "Clean complete."
