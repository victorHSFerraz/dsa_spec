CC=gcc
CFLAGS=-I./include -I./tests
SRC=$(wildcard src/*.c)     
SRC_WITHOUT_MAIN=$(filter-out src/main.c, $(SRC))
TEST_SUITES=$(wildcard tests/test_suites/*.c)

all: 
	main

main: 
	$(CC) $(CFLAGS) -o main $(SRC)
	main
	
test:
	$(CC) $(CFLAGS) $(TEST_SUITES) tests/test_main.c tests/unity/unity.c $(SRC_WITHOUT_MAIN) -o test_main
	test_main
	


