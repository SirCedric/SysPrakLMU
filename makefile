CFLAGS = -Wall -Wextra -Werror

CC = gcc

GAME_ID?=3q74u16xipvmd

PLAYER?=1

make: main.c performConnection.c parameter.c
	$(CC) $(CFLAGS) -o sysprak-client main.c performConnection.c parameter.c thinker.c

play:	
	./sysprak-client -g $(GAME_ID) -p $(PLAYER)

clean:
	rm -f *.o play./ sysprak-client
