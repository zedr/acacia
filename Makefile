build:
	gcc -g -Wall -Wextra -s acacia.c -o acacia

clean:
	rm acacia acacia_tests

valgrind:
	gcc -g -Wall -Wextra -s acacia_tests.c -o acacia_tests
	valgrind ./acacia_tests

tests:
	gcc -g -lrt -lm -s -Wall -Wextra acacia_tests.c -o acacia_tests
	./acacia_tests

default: build
