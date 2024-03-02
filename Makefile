CC := gcc
CFLAGS := -Wall -Wextra -O2
LDFLAGS := 

# Directories
SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj
TESTS_DIR := tests

# Files
SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/core/*.c) $(wildcard $(SRC_DIR)/io/*.c) $(wildcard $(SRC_DIR)/buffer/*.c) $(wildcard $(SRC_DIR)/utils/*.c) $(wildcard $(SRC_DIR)/algorithms/*.c) $(wildcard $(SRC_DIR)/benchmarks/*.c) $(wildcard $(SRC_DIR)/tests/*.c)


# Objects
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets
MAIN := $(BIN_DIR)/micromal

# Rules
all: build $(MAIN)

# Rule to create the main executable
$(MAIN): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) -o $@ $^

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

build:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

# Rule to clean the project
clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)

# Phony targets
.PHONY: all build clean