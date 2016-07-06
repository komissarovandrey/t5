CC=gcc
CFLAGS=-c -Wall

all: dd

dd: main.o
	$(CC) main.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o main
