all: tests

build: acacia.c acacia.h
	$(CC) -Wall -Wextra -std=c99 -pedantic -O2 -s acacia.c -o acacia

clean:
	rm acacia acacia_tests

valgrind: acacia.c acacia.h acacia_tests.c
	$(CC) -g -Wall -Wextra -O2 -s acacia.c -s acacia_tests.c -o acacia_tests
	valgrind ./acacia_tests

tests: acacia.c acacia.h acacia_tests.c
	gcc -g -lrt -lm -Wall -Wextra -s acacia.c -s acacia_tests.c -o acacia_tests
	./acacia_tests

default: build
