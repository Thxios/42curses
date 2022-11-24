
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_DIR =	libft
LIBFT =		libft.a
LIB =		$(LIBFT_DIR)/$(LIBFT)

BASE_SRCS =	ft_printf.c \
			format_parser.c \
			format_print.c

ifdef DO_BONUS
	FUNC_SRCS = $(wildcard f_types/*.c)
else
	FUNC_SRCS = $(wildcard f_types/*.c)
endif

SRCS = $(BASE_SRCS) $(FUNC_SRCS)
OBJS = $(SRCS:.c=.o)

INCLUDES = .

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

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

test: test.c $(NAME)
	gcc $^ -o $@

.PHONY: all clean fclean re bonus
