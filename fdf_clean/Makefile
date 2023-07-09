

CC =		gcc
# CFLAGS =	-Wall -Wextra -fsanitize=address
CFLAGS =	-Wall -Wextra -fsanitize=address -Wall
# CFLAGS =	-Wall -Wextra -Wall

NAME =	fdf


LIB_DIR =	libraries
LIBFT =		$(LIB_DIR)/libft/libft.a
LIBMLX =	$(LIB_DIR)/libmlx/libmlx.a

LIB_FLAGS =	-L$(dir $(LIBFT)) -L$(dir $(LIBMLX)) \
			-lft -lmlx \
			-lm -framework OpenGL -framework AppKit
			# -lm -lX11 -lXext


INC_PATHS =	includes \
			$(dir $(LIBFT)) \
			$(dir $(LIBMLX))
INC_FLAGS =	$(addprefix -I, $(INC_PATHS))


SRCS_DIR =	sources

CTX_DIR =	context
CTX_SRCS =	\
			context.c

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
				key_event.c \
				mouse_event.c

OBJECT_DIR =	object
OBJECT_SRCS =	\
				object.c \
				parse_map_info.c \
				build_obj.c \
				read_file.c

UTIL_DIR =	utils
UTIL_SRCS =	\
			alloc_utils.c \
			num_utils.c \
			parse_utils.c \
			time_utils.c \
			matrix.c \
			quaternion.c \
			vector.c \
			ptr_array.c \
			error.c

MANDAT_DIR =	mandatory
MANDAT_SRCS =	\
				draw_edge.c \
				hook.c
BONUS_DIR =		bonus
BONUS_SRCS =	\
				draw_edge_bonus.c \
				hook_bonus.c

MAIN_SRC =	\
			fdf.c \
			initialize.c


SRCS_BASE =	$(MAIN_SRC) \
			$(addprefix $(CTX_DIR)/, $(CTX_SRCS)) \
			$(addprefix $(RENDER_DIR)/, $(RENDER_SRCS)) \
			$(addprefix $(CAMERA_DIR)/, $(CAMERA_SRCS)) \
			$(addprefix $(EVENTS_DIR)/, $(EVENTS_SRCS)) \
			$(addprefix $(OBJECT_DIR)/, $(OBJECT_SRCS)) \
			$(addprefix $(UTIL_DIR)/, $(UTIL_SRCS))

SRCS =		$(addprefix $(SRCS_DIR)/, $(SRCS_BASE))
OBJS =		$(SRCS:.c=.o)

MANDAT_BASE =	$(addprefix $(SRCS_DIR)/$(MANDAT_DIR)/, $(MANDAT_SRCS))
MANDAT_OBJS =	$(MANDAT_BASE:.c=.o)

BONUS_BASE =	$(addprefix $(SRCS_DIR)/$(BONUS_DIR)/, $(BONUS_SRCS))
BONUS_OBJS =	$(BONUS_BASE:.c=.o)

ifdef BUILD_BONUS
COMPLEMENTARY =	$(BONUS_OBJS)
else
COMPLEMENTARY = $(MANDAT_OBJS)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $^ -o $@

$(LIB_DIR)/%.a:
	$(MAKE) all -C $(dir $@)

$(NAME): $(OBJS) $(COMPLEMENTARY) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(COMPLEMENTARY) -o $@ $(LIB_FLAGS)

clean:
	$(MAKE) fclean -C $(dir $(LIBFT))
	$(MAKE) clean -C $(dir $(LIBMLX))
	rm -f $(OBJS) $(MANDAT_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

bonus:
	$(MAKE) BUILD_BONUS=1 all

.PHONY: all clean fclean re bonus
