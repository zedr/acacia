build:
	gcc -Wall -s acacia.c -o acacia

clean:
	rm acacia

valgrind: acacia
	valgrind ./acacia

tests:
	gcc -lrt -lm -s acacia_tests.c -o acacia_tests
	./acacia_tests

default: build