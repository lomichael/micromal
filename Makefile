CC=gcc
CFLAGS=-Iinclude -Wall

SRC_DIR=src
OBJ_DIR=obj
TEST_DIR=tests

LIB_SOURCES=$(wildcard $(SRC_DIR)/*.c)
LIB_OBJECTS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SOURCES))

TEST_SOURCES=$(wildcard $(TEST_DIR)/*.c)
TESTS=$(patsubst $(TEST_DIR)/%.c,%,$(TEST_SOURCES))

all: $(TESTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%: $(TEST_DIR)/%.c $(LIB_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

tests: $(TESTS)
	@for test in $(TESTS); do \
		./$$test; \
	done

clean:
	rm -rf $(OBJ_DIR)/*.o $(TESTS)

.PHONY: all clean tests
