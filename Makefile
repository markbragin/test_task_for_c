CC := cc
CFLAGS := -Wall -Wextra -Wpedantic -g -ansi -pedantic
LDFLAGS := -lm

BUILD_DIR := build
SRC_DIR := src
TESTS_DIR := tests
TEST_BINARY := run_test

$(shell mkdir -p $(BUILD_DIR))

$(TEST_BINARY): $(BUILD_DIR)/quadratic_equation_test.o \
			    $(BUILD_DIR)/quadratic_equation.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/quadratic_equation_test.o \
		$(BUILD_DIR)/quadratic_equation.o -o $(TEST_BINARY) $(LDFLAGS)

$(BUILD_DIR)/quadratic_equation_test.o: $(TESTS_DIR)/quadratic_equation_test.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/quadratic_equation.o: $(SRC_DIR)/quadratic_equation.c $(SRC_DIR)/quadratic_equation.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean check

clean:
	rm -rf build $(TEST_BINARY)

check: $(TEST_BINARY)
	@./$(TEST_BINARY)
