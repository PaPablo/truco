CC=gcc
CFLAGS=-Wall
OBJ = bin/card.o src/main.c


truco: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o bin/truco

bin/card.o: src/card.h
	gcc -c src/card.c -o bin/card.o

bin/main.o: src/card.h
	gcc -c src/card.c src/main.c -o bin/main.o


