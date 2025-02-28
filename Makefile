SRCS =  server.c \
        ft_printf/ft_printf.c ft_printf/ft_format.c ft_printf/ft_putstr.c\
        ft_printf/ft_putchar.c ft_printf/ft_putnbr.c\

SRC_C = client.c libft/ft_atoi.c \
	ft_printf/ft_printf.c ft_printf/ft_format.c ft_printf/ft_putstr.c\
	ft_printf/ft_putchar.c ft_printf/ft_putnbr.c\

SRCS_B =  server_bonus.c \
        ft_printf/ft_printf.c ft_printf/ft_format.c ft_printf/ft_putstr.c\
        ft_printf/ft_putchar.c ft_printf/ft_putnbr.c\

SRC_C_B = client_bonus.c libft/ft_atoi.c \
	ft_printf/ft_printf.c ft_printf/ft_format.c ft_printf/ft_putstr.c\
	ft_printf/ft_putchar.c ft_printf/ft_putnbr.c\

OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRC_C:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
OBJS_C_B = $(SRC_C_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all:$(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(SERVER)

$(CLIENT) : $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(OBJS_C_B)
	$(CC) $(CFLAGS) $(OBJS_C_B) -o $(CLIENT_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_C) $(OBJS_B) $(OBJS_C_B)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

re_bonus: fclean bonus

.SECONDARY:$(OBJS) $(OBJS_C) $(OBJS_B) $(OBJS_C_B)
