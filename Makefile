CFLAGS=-Wall 
LFLAGS=-lm
CC=gcc

all: filter.o 
	$(CC) $(CFLAGS) $(LFLAGS) filter.o example.c -o example

filter.o:
	$(CC) $(CFLAGS) -c filter.c

clean:
	\rm filter.o example
