
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

PUSH_SWAP =	push_swap
CHECKER =	checker

ifdef BUILD_CHECKER
NAME =	$(CHECKER)
else
NAME =	$(PUSH_SWAP)
endif


LIB_DIR =	libraries
LIB_NAMES =	libft
LIBS = 		$(foreach LIB,$(LIB_NAMES),$(LIB_DIR)/$(LIB)/$(LIB).a)


INCLUDES =	includes \
			libraries
INC_FLAGS =	$(addprefix -I , $(INCLUDES))


SRCS_DIR =	sources

UTIL_DIR =	utils
UTIL_SRCS =	\
			array.c \
			deque.c \
			deque2.c \
			comp.c \
			quick_sort.c \
			safe_malloc.c

INST_DIR =	context
INST_SRCS =	\
			context.c \
			initialize.c \
			inst_push.c \
			inst_swap.c \
			inst_rotate.c \
			inst_rev_rotate.c \
			mapping.c

PARSER_DIR =	parser
PARSER_SRCS =	\
				parse_args.c \
				check_unique.c

SOLVER_DIR =	solver
SOLVER_SRCS =	\
				sort.c \
				move.c \
				merge.c \
				merge_config.c \
				manual.c \
				manual_a.c \
				manual_b.c

SRCS_SRCS =	\
			$(addprefix $(UTIL_DIR)/, $(UTIL_SRCS)) \
			$(addprefix $(INST_DIR)/, $(INST_SRCS)) \
			$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS)) \
			$(addprefix $(SOLVER_DIR)/, $(SOLVER_SRCS))
SRCS =		$(addprefix $(SRCS_DIR)/, $(SRCS_SRCS))
OBJS =		$(SRCS:.c=.o)

PUSH_SWAP_SRC =	push_swap.c
CHECKER_SRC =	checker.c
PUSH_SWAP_OBJ =	$(SRCS_DIR)/$(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ =	$(SRCS_DIR)/$(CHECKER_SRC:.c=.o)

ifdef BUILD_CHECKER
MAIN_OBJ =	$(CHECKER_OBJ)
else
MAIN_OBJ =	$(PUSH_SWAP_OBJ)
endif


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $^ -o $@

$(LIB_DIR)/%.a:
	$(MAKE) all -C $(dir $@)

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(INC_FLAGS) $^ -o $@

clean:
	$(foreach LIB,$(LIBS),$(MAKE) fclean -C $(dir $(LIB)))
	rm -f $(OBJS) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)

fclean: clean
	rm -f $(PUSH_SWAP) $(CHECKER)

re:	fclean all

bonus:
	$(MAKE) BUILD_CHECKER=1 all

.PHONY: all clean fclean re bonus
