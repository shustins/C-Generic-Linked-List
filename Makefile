IDIR=include
CC=gcc
CFLAGS=-Wall -std=c99 -g -I$(IDIR)
SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
EXECUTABLE=listTest

all: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

clean:
	rm -f *.o $(EXECUTABLE)