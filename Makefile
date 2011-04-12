CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror

run-test : build-release
	./test

run-debug : build-debug
	./test

run-gdb : build-debug
	gdb ./test

run-valgrind : build-debug
	valgrind --leak-check=yes --show-reachable=yes --tool=memcheck ./test

build-release : CFLAGS += -O2
build-release : list.o test.c list.h
	$(CC) $(CFLAGS) test.c list.o -o test

build-debug : CFLAGS += -g -DDEBUG
build-debug : list.o test.c list.h
	$(CC) $(CFLAGS) test.c list.o -o test

list.o : list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean :
	rm *.o test
