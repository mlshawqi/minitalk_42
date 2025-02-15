SRCS =  server.c libft/ft_calloc.c libft/ft_strlen.c\

SRC_C = client.c libft/ft_atoi.c \


OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRC_C:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client

all:$(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(SERVER)

$(CLIENT) : $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(CLIENT)

clean:
	rm -f $(OBJS) $(OBJS_C)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
.SECONDARY:$(OBJS) $(OBJS_C)
