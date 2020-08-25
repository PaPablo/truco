CC=gcc
CFLAGS=-Wall
OBJ = src/card.c src/main.c


truco: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o bin/truco

