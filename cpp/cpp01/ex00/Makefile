
CCC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98


NAME =	zombie


SRCS =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp
OBJS =	$(SRCS:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	$(CCC) $(CXXFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CCC) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
