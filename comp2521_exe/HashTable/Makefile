CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

# Detect the operating system
UNAME_S := $(shell uname -s)

# For macOS, modify CFLAGS to exclude the leak sanitizer
ifeq ($(UNAME_S),Darwin)
    CFLAGS := -Wall -Werror -g -fsanitize=address,undefined
endif

.PHONY: all
all: runChaining runLinearProbing runDoubleHashing

runChaining: runHashTable.c HashTableChaining.c
	$(CC) $(CFLAGS) -o runChaining runHashTable.c HashTableChaining.c

runLinearProbing: runHashTable.c HashTableLinearProbing.c
	$(CC) $(CFLAGS) -o runLinearProbing runHashTable.c HashTableLinearProbing.c

runDoubleHashing: runHashTable.c HashTableDoubleHashing.c
	$(CC) $(CFLAGS) -o runDoubleHashing runHashTable.c HashTableDoubleHashing.c

.PHONY: clean
clean:
	rm -f runChaining runLinearProbing runDoubleHashing
