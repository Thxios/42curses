
CCC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98


NAME =	materia


SRCS =	main.cpp \
		AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		MateriaSource.cpp \
		Character.cpp
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
