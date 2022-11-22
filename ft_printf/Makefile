
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_DIR =	libft
LIBFT =		libft.a
LIB =		$(LIBFT_DIR)/$(LIBFT)

SRCS = 	ft_printf.c \
		format_parser.c \
		format_print.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(LIB)
	ar rcs $@ $^

$(LIB):
	make all -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

bonus:
	make DO_BONUS=1 all

.PHONY: all clean fclean re bonus
