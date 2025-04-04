CC = gcc
CFLAGS = -Wall -Wextra -std=c99
INCLUDES = -I../../include
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC_DIR = src/core
BUILD_DIR = ../../build
BIN_DIR = ../../bin

TARGET = $(BIN_DIR)/physics-app

all: directories $(TARGET)

directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# Direct compilation without intermediate object files
$(TARGET): directories $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(SRC_DIR)/main.c $(LIBS)
	@echo "Compilation complete!"

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Cleanup complete!"

.PHONY: all clean directories
