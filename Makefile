CC := gcc
CFLAGS := -Wall -g 
LDFLAGS := 

# Directories
SRC_DIR := src
ALGO_DIR := $(SRC_DIR)/algorithms
CORE_DIR := $(SRC_DIR)/core
UTILS_DIR := $(SRC_DIR)/utils
TESTS_DIR := tests
OBJ_DIR := obj
BIN_DIR := bin

# Files
ALGO_SRCS := $(ALGO_DIR)/huffman/huffman.c
CORE_SRCS := $(CORE_DIR)/main.c $(CORE_DIR)/buffer.c
UTILS_SRCS := $(UTILS_DIR)/io.c $(UTILS_DIR)/log.c $(UTILS_DIR)/mem.c
TESTS_SRCS := $(TESTS_DIR)/benchmarks/benchmark.c

# Objects
OBJS := $(ALGO_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
		$(CORE_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
		$(UTILS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
		$(TESTS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets
MICROMAL := $(BIN_DIR)/micromal

# Rules
all: $(MICROMAL)

# Rule to create the main executable
$(MICROMAL): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to create the object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

# Rule to clean the project
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean