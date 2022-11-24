
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_DIR =	libft
LIBFT =		libft.a
LIB =		$(LIBFT_DIR)/$(LIBFT)

BASE_SRCS =	ft_printf.c \
			format_parser.c \
			format_print.c \
			$(wildcard utils/*.c)
BASE_OBJS = $(BASE_SRCS:.c=.o)


FUNC_SRCS = $(wildcard f_types/*.c)
FUNC_BONUS_SRCS = $(wildcard f_types_bonus/*.c)

FUNC_OBJS = $(FUNC_SRCS:.c=.o)
FUNC_BONUS_OBJS = $(FUNC_BONUS_SRCS:.c=.o)

ifdef DO_BONUS
	OBJS = $(BASE_OBJS) $(FUNC_BONUS_OBJS)
else
	OBJS = $(BASE_OBJS) $(FUNC_OFUNC_BONUS_OBJS)
endif

INCLUDES = .

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(NAME): $(LIB) $(OBJS)
	cp $< $@
	ar rcs $@ $^

$(LIB):
	make all -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(BASE_OBJS) $(FUNC_OBJS) $(FUNC_BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

test: test.c $(NAME) $(FUNC_BONUS_OBJS)
	make DO_BONUS=1 $(NAME)
	gcc test.c $(NAME) -o $@

bonus:
	make DO_BONUS=1 all

.PHONY: all clean fclean re bonus
