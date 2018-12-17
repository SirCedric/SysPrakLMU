CFLAGS = -Wall -Wextra -Werror

CC = gcc

GAME_ID?=1s4wsdo0v92ve

PLAYER?=1

play: main.c performConnection.c parameter.c
	$(CC) $(CFLAGS) -o sysprak-client main.c performConnection.c parameter.c
	./sysprak-client -g $(GAME_ID) -p $(PLAYER)

clean:
	rm -f *.o play./
