CC=gcc
CFLAGS=-I./include
SRC=$(wildcard src/*.c)     
SRC_WITHOUT_MAIN=$(filter-out src/main.c, $(SRC))

all: 
	main

main: 
	$(CC) $(CFLAGS) -o main $(SRC)
	main
	
test:
	$(CC) $(CFLAGS) tests/*.c tests/unity/unity.c $(SRC_WITHOUT_MAIN) -o test_main
	test_main
	


