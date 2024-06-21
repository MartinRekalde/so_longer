NAME = so_long

CC = gcc -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

LMLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx

RM = rm -rf

SRCS_DIR = sources/
MLX_DIR = mlx
MLX_LIB = /libmlx.a

SRCS = $(SRCS_DIR)so_long.c $(SRCS_DIR)1_map.c $(SRCS_DIR)2_map.c $(SRCS_DIR)error.c \
	$(SRCS_DIR)hook.c $(SRCS_DIR)movement.c $(SRCS_DIR)start_game.c $(SRCS_DIR)textures.c \
	$(SRCS_DIR)validate.c $(SRCS_DIR)xpm.c $(SRCS_DIR)flood_fill.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	libft/ft_strcmp.c libft/ft_strrchr.c libft/ft_split.c libft/ft_substr.c libft/ft_strlcpy.c

OBJS_DIR = objects/
OBJS = $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

INCLUDES = -I/usr/include -Imlx -Ignl -Ilibft
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(MLX_LIB) $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -rf $(OBJS_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re