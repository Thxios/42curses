
CC =		cc
CCC =		c++
CFLAGS =	-Wall -Wextra -Werror


NAME =	phonebook


SRCS =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp
OBJS =	$(SRCS:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	$(CCC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CCC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
