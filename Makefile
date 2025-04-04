# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
INCLUDES = -I../../include
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRC_DIR = src/core
LIB_DIR = src/lib
BUILD_DIR = ../../build
BIN_DIR = ../../bin

# Files
SRC_FILES = $(SRC_DIR)/main.c
LIB_FILES = $(LIB_DIR)/physics.c
TARGET = $(BIN_DIR)/physics-app

# Default rule
all: directories $(TARGET)

# Create build/bin directories
directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# Linking and compilation
$(TARGET): $(SRC_FILES) $(LIB_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)
	@echo "Compilation complete!"

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Cleanup complete!"

.PHONY: all clean directories
