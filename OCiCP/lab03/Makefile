rwildcard = $(filter-out \ ,$(foreach pattern,$(2),$(wildcard $(1)/$(pattern)))$(foreach child,$(wildcard $(1)/*),$(call rwildcard,$(child),$(2))))

eq = $(and $(findstring $(1),$(2)),$(findstring $(2),$(1)))

TARGET ?= parent
BUILD_DIR = build

DEBUG_SUFFIX = $(if $(call eq,$(MODE),debug),-debug)
CFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c11 -Isrc/main/ $(if $(call eq,$(MODE),debug),-ggdb)
CC = gcc $(CFLAGS)
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all
GDB = gdb
GDB_COMMANDS = $(BUILD_DIR)/gdb-commands.txt

SOURCES = $(call rwildcard,src/main,*.c)
OBJECTS = $(foreach source,$(SOURCES),$(call object,$(source)))
MAINS = $(wildcard src/cmd/*.c)
EXECUTABLES = $(foreach main,$(MAINS),$(call executable,$(main)))

target = $(BUILD_DIR)/$(1)$(DEBUG_SUFFIX)
executable = $(BUILD_DIR)/$(patsubst %.c,%,$(notdir $(1)))$(DEBUG_SUFFIX)
object = $(BUILD_DIR)/$(patsubst %.c,%,$(1))$(DEBUG_SUFFIX).o
dependencies = $(CC) -MM $(1) -MT $(2)

.PHONY: all
all: app

.PHONY: run
run: $(EXECUTABLES)
	$(call target,$(TARGET))

.PHONE: vrun
vrun: $(EXECUTABLES)
	$(VALGRIND) $(call target,$(TARGET))

.PHONE: gdb
gdb: $(EXECUTABLES) $(GDB_COMMANDS)
	$(GDB) -x $(GDB_COMMANDS) -q $(call target,$(TARGET))

.PHONY: app
app: $(EXECUTABLES)

$(foreach source,$(SOURCES),$(eval $(shell $(call dependencies,$(source),$(call object,$(source))))))
$(foreach main,$(MAINS),$(eval $(shell $(call dependencies,$(main),$(call executable,$(main))))))

$(EXECUTABLES): $(call executable,%): src/cmd/%.c $(OBJECTS)
	mkdir -p $(dir $@)
	$(CC) $< $(OBJECTS) -o $@

$(OBJECTS): $(call object,%.c): %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(GDB_COMMANDS):
	mkdir -p $(dir $@)
	echo run finish > $@
	echo bt 10 >> $@

.PHONY: all
clean:
	rm -rf $(BUILD_DIR)
