
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT =	libft/libft.a
LIB =	$(LIBFT)

BASE_SRCS =	ft_printf.c \
			format/format_parser.c \
			format/format_print.c \
			utils/num_utils.c \
			utils/pad_utils.c
BASE_OBJS = $(BASE_SRCS:.c=.o)

FUNC_SRCS =	f_types/f_types.c \
			f_types/func_char_str.c \
			f_types/func_dec_int_uint.c \
			f_types/func_hex_ptr.c \
			f_types/func_invalid_percent.c
FUNC_OBJS = $(FUNC_SRCS:.c=.o)

FUNC_BONUS_SRCS =	f_types_bonus/f_types_bonus.c \
					f_types_bonus/func_char_str_bonus.c \
					f_types_bonus/func_dec_int_uint_bonus.c \
					f_types_bonus/func_hex_bonus.c \
					f_types_bonus/func_ptr_bonus.c \
					f_types_bonus/func_invalid_percent_bonus.c
FUNC_BONUS_OBJS =	$(FUNC_BONUS_SRCS:.c=.o)

INCLUDES = .

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(NAME): $(LIB) $(BASE_OBJS) $(FUNC_OBJS)
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

bonus: $(LIB) $(BASE_OBJS) $(FUNC_BONUS_OBJS)
	cp $< $(NAME)
	ar rcs $(NAME) $^

.PHONY: all clean fclean re bonus
