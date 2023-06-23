
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

NAME =	pipex

LIB_DIR =	libraries
LIB_NAMES =	libft
LIBS =		$(foreach LIB,$(LIB_NAMES),$(LIB_DIR)/$(LIB)/$(LIB).a)


INCLUDES =	includes \
			libraries
INC_FLAGS =	$(addprefix -I , $(INCLUDES))


SRCS_DIR =	sources

UTIL_DIR =	utils
UTIL_SRCS =	\
			utils.c \
			info.c \
			str_array.c \
			char_array.c \
			error.c

PARSER_DIR =	parser
PARSER_SRCS =	\
				parser.c \
				parse_env.c

COMM_DIR =	command
COMM_SRCS =	\
			command.c \
			find_prefix.c

PIPE_DIR =	pipe
PIPE_SRCS =	\
			here_doc.c \
			pipe.c \
			pipe2.c

SRCS_SRCS =	\
			$(addprefix $(UTIL_DIR)/, $(UTIL_SRCS)) \
			$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS)) \
			$(addprefix $(COMM_DIR)/, $(COMM_SRCS)) \
			$(addprefix $(PIPE_DIR)/, $(PIPE_SRCS))
SRCS =		$(addprefix $(SRCS_DIR)/, $(SRCS_SRCS))
OBJS =		$(SRCS:.c=.o)

PIPEX_SRC =	pipex.c
PIPEX_OBJ =	$(SRCS_DIR)/$(PIPEX_SRC:.c=.o)

MAIN_OBJ =	$(PIPEX_OBJ)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $^ -o $@

$(LIB_DIR)/%.a:
	$(MAKE) all -C $(dir $@)

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(INC_FLAGS) $^ -o $@

clean:
	$(foreach LIB,$(LIBS),$(MAKE) fclean -C $(dir $(LIB)))
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
