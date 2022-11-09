
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

BONUS_SRCS = $(wildcard ft_*_bonus.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

SRCS = $(filter-out $(BONUS_SRCS), $(wildcard ft_*.c))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $@ $^

.PHONY: all clean fclean re bonus
