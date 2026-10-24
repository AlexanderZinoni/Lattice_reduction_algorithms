CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDLIBS = -lm

all: main

SRC = src
INC = include

utils.o: $(SRC)/utils.c $(INC)/utils.h
	$(CC) $(CFLAGS) -c $(SRC)/utils.c -o utils.o

matrix.o: $(SRC)/matrix.c $(INC)/utils.h
	$(CC) $(CFLAGS) -c $(SRC)/matrix.c -o matrix.o

LLL.o: $(SRC)/LLL.c $(INC)/utils.h
	$(CC) $(CFLAGS) -c $(SRC)/LLL.c -o LLL.o

main.o:  $(SRC)/main.c $(INC)/LLL.h $(INC)/matrix.h $(INC)/utils.h
	$(CC) $(CFLAGS) -c $(SRC)/main.c -o main.o

main: main.o LLL.o matrix.o utils.o
	$(CC) $^ -o $@ $(LDLIBS)

clean:
	rm -f main *.o

.PHONY: all clean