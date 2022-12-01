
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_DIR =	libft
LIBFT =		libft.a
LIB =		$(LIBFT_DIR)/$(LIBFT)

BASE_SRCS =	ft_printf.c \
			format_parser.c \
			format_print.c \
			utils/num_utils.c \
			utils/pad_utils.c
BASE_OBJS = $(BASE_SRCS:.c=.o)

FUNC_SRCS =	f_types/f_types.c \
			f_types/func_char_str.c \
			f_types/func_dec_int_uint.c \
			f_types/func_hex_ptr.c \
			f_types/func_invalid_percent.c
FUNC_BONUS_SRCS = $(wildcard f_types_bonus/*.c)

FUNC_OBJS = $(FUNC_SRCS:.c=.o)
FUNC_BONUS_OBJS = $(FUNC_BONUS_SRCS:.c=.o)

ifdef DO_BONUS
	OBJS = $(BASE_OBJS) $(FUNC_BONUS_OBJS)
else
	# OBJS = $(BASE_OBJS) $(FUNC_OBJS)
	OBJS = $(BASE_OBJS) $(FUNC_BONUS_OBJS)
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

test: test.c $(BASE_OBJS) $(FUNC_BONUS_OBJS)
	make bonus
	gcc test.c $(NAME) -o $@

bonus:
	make DO_BONUS=1 all -C .

.PHONY: all clean fclean re bonus
