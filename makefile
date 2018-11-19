CFLAGS = -Wall -Wextra -Werror

CC = clang

GAME_ID?=0

PLAYER?=0

all: play

play: main.c performConnection.c
	$(CC) $(CFLAGS) -o sysprak-client main.c performConnection.c
	./sysprak-client -g $(GAME_ID) -p $(PLAYER)

clean:
	rm -f *.o play