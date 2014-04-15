build:
	gcc -g -Wall -s acacia.c -o acacia

clean:
	rm acacia acacia_tests

valgrind: acacia
	valgrind ./acacia

tests:
	gcc -g -lrt -lm -s acacia_tests.c -o acacia_tests
	./acacia_tests

default: build
