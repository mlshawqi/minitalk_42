SRCS =  server.c\

SRC_C = client.c \


OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRC_C:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server
NAME_C = client

all:$(NAME)

$(NAME): $(OBJS)
        $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

cl : $(OBJB)
        $(CC) $(CFLAGS) $(OBJB) -o $(NAME_B)

clean:
        rm -f $(OBJS)

clean_b:
        rm -f $(OBJB)


fclean: clean
        rm -f $(NAME)

fclean_b: clean_b
        rm -f $(NAME_B)

re: fclean all
re_b: fclean_b bonus
.SECONDARY:$(OBJS) $(OBJB)%