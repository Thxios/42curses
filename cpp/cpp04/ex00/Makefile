
CCC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98


NAME =	animal


SRCS =	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		WrongDog.cpp
OBJS =	$(SRCS:.cpp=.o)


all: $(NAME)

main.o: main.cpp
	$(CCC) $(CXXFLAGS) -c $^ -o $@

%.o: %.cpp %.h
	$(CCC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CCC) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
