CC = gcc
CFLAGS = -lSDL2_image -lSDL2_image `sdl2-config --cflags --libs`

all: game

game: main.o res.o
	$(CC) main.o res.o -o game $(CFLAGS)
res.o: res.c
	$(CC) res.c $(CFLAGS) -c
main.o: main.c
	$(CC) main.c $(CFLAGS) -c


clean:
	rm -rf *o game
