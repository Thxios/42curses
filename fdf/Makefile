

CC =		gcc
# CFLAGS =	-Wall -Wextra -fsanitize=address
CFLAGS =	-Wall -Wextra

NAME =	fdf


LIB_DIR =	libraries
LIB_NAMES =	\
			libft \
			libmlx
LIBS = 		$(foreach LIB,$(LIB_NAMES),$(LIB_DIR)/$(LIB)/$(LIB).a)
LIB_FLAGS =	$(addprefix -L$(LIB_DIR)/, $(LIB_NAMES)) \
			$(addprefix -l, $(subst lib,,$(LIB_NAMES))) \
			-lX11 -lm -lXext


INCLUDES =	includes \
			$(addprefix $(LIB_DIR)/, $(LIB_NAMES))
			# $(LIB_DIR)
INC_FLAGS =	$(addprefix -I, $(INCLUDES))


SRCS_DIR =	sources

CTX_DIR =	context
CTX_SRCS =	\
			context.c \
			initialize.c

RENDER_DIR =	render
RENDER_SRCS =	\
				render.c \
				buffer.c \
				draw.c \
				draw_line.c \
				draw_line_grad.c \
				draw_obj.c \
				color.c

CAMERA_DIR =	camera
CAMERA_SRCS =	\
				camera.c \
				zoom.c \
				ortho.c \
				persp.c

EVENTS_DIR =	events
EVENTS_SRCS =	\
				quit.c \
				keydown.c \
				mousedown.c

UPDATE_DIR =	update
UPDATE_SRCS =	\
				frame.c

OBJECT_DIR =	object
OBJECT_SRCS =	\
				object.c

UTIL_DIR =	utils
UTIL_SRCS =	\
			utils.c \
			matrix.c \
			point.c \
			quaternion.c \
			vector.c \
			error.c

SRCS_BASE = \
			$(addprefix $(CTX_DIR)/, $(CTX_SRCS)) \
			$(addprefix $(RENDER_DIR)/, $(RENDER_SRCS)) \
			$(addprefix $(CAMERA_DIR)/, $(CAMERA_SRCS)) \
			$(addprefix $(EVENTS_DIR)/, $(EVENTS_SRCS)) \
			$(addprefix $(UPDATE_DIR)/, $(UPDATE_SRCS)) \
			$(addprefix $(OBJECT_DIR)/, $(OBJECT_SRCS)) \
			$(addprefix $(UTIL_DIR)/, $(UTIL_SRCS))

SRCS =		$(addprefix $(SRCS_DIR)/, $(SRCS_BASE))
OBJS =		$(SRCS:.c=.o)

OBJS_TEST =	$(addprefix build/, $(notdir $(SRCS:.c=.o)))

MAIN_SRC =	test.c
MAIN_OBJ =	$(SRCS_DIR)/$(MAIN_SRC:.c=.o)



all: $(NAME)

echo:
	@echo $(OBJS_TEST)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $^ -o $@

$(LIB_DIR)/%.a:
	$(MAKE) all -C $(dir $@)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(INC_FLAGS) $^ -o $@ $(LIB_FLAGS)

clean:
	# for LIB_NAME in $(LIB_NAMES) ; do \
	# 	$(MAKE) clean -C $(LIB_DIR)/$$LIB_NAME ; \
	# done
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
