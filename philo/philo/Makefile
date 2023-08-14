
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

NAME =	philo

SRCS =	main.c \
		fork.c \
		philo.c \
		philo2.c \
		logger.c \
		thread.c \
		simulation.c \
		simulation2.c \
		time_util.c \
		utils.c
OBJS =	$(SRCS:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
