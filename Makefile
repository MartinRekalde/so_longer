NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LMLX	= -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
RM		= rm -rf

SRCS_DIR	=	sources/
MLX_DIR		=	mlx
MLX_LIB		=	/libmlx.a
SRCS		=	so_long.c 1_map.c 2_map.c error.c hook.c movement.c start_game.c textures.c validate.c xpm.c\
				libft/ft_putendl.c li libft/ft_strcmp.c libft/ft_strrchr.c libft/ft_split.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
