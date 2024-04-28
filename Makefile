ifeq ($(origin CC),default)
	CC = gcc
endif

CFLAGS ?= -Wall -Wpedantic -g -ansi -pedantic
LDFLAGS ?= -lm

TEST_BINARY ?= run_test
BUILD_DIR ?= build

SOURCES = src/quadratic_equation.c
OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJECTS:%.o=%.d)

INCLUDE_FLAGS = -I./src
override CFLAGS += $(INCLUDE_FLAGS)

TESTS = tests/quadratic_equation_test.c
TESTSOBJ = $(TESTS:%.c=$(BUILD_DIR)/%.o)


$(TEST_BINARY): $(TESTSOBJ) $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJECTS) $(TESTSOBJ): $(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEPS): $(BUILD_DIR)/%.d: %.c
	@mkdir -p $(@D)
	$(CC) -E $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEST_BINARY)

.PHONY: check
check: $(TEST_BINARY)
	@./$(TEST_BINARY)

NODEPS = clean

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
include $(DEPS)
endif
