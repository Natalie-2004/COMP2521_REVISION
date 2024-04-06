CC = clang
CFLAGS = -Wall -Werror

# Check for macOS and adjust CFLAGS for sanitizer support
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    CFLAGS += -fsanitize=address -fsanitize=undefined
else
    CFLAGS += -fsanitize=address,leak,undefined
endif

.PHONY: all
all: cycle components hamiltonianPath hamiltonianCircuit eulerianPath

cycle: cycle.c Graph.c
	$(CC) $(CFLAGS) -o cycle cycle.c Graph.c

components: components.c Graph.c
	$(CC) $(CFLAGS) -o components components.c Graph.c

hamiltonianPath: hamiltonianPath.c Graph.c
	$(CC) $(CFLAGS) -o hamiltonianPath hamiltonianPath.c Graph.c

hamiltonianCircuit: hamiltonianCircuit.c Graph.c
	$(CC) $(CFLAGS) -o hamiltonianCircuit hamiltonianCircuit.c Graph.c

eulerianPath: eulerianPath.c Graph.c
	$(CC) $(CFLAGS) -o eulerianPath eulerianPath.c Graph.c

eulerianCircuit: eulerianCircuit.c Graph.c
	$(CC) $(CFLAGS) -o eulerianCircuit eulerianCircuit.c Graph.c

.PHONY: clean
clean:
	rm -rf *.dSYM
	rm -f cycle components hamiltonianPath hamiltonianCircuit eulerianPath eulerianCircuit
