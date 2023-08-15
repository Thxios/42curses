
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

NAME =	philo

SRCS =	main.c \
		philo.c \
		logger.c \
		sem.c \
		process.c \
		simulation.c \
		time_util.c \
		utils.c
OBJS =	$(SRCS:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -pthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
