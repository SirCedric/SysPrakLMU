CFLAGS = -Wall -Wextra -Werror

CC = clang

GAME_ID?=0iu4bs2uyir1e

PLAYER?=1

play: main.c performConnection.c parameter.c
	$(CC) $(CFLAGS) -o sysprak-client main.c performConnection.c parameter.c
	./sysprak-client -g $(GAME_ID) -p $(PLAYER)

clean:
	rm -f *.o play./