CFLAGS=-Wall
LFLAGS=-lm
CC=gcc

all: filter.o tinywav.o
	$(CC) $(CFLAGS) $(LFLAGS) filter.o tinywav.o lpbutter_wav.c -o lpbutter_wav

tinywav.o:
	$(CC) $(CFLAGS) -c tinywav.c

example: filter.o
	$(CC) $(CFLAGS) $(LFLAGS) filter.o example.c -o example

filter.o:
	$(CC) $(CFLAGS) -c filter.c

clean:
	\rm *.o lpbutter_wav
