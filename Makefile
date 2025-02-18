NAME = cub3D
LIBFT = libft/libft.a
CC = gcc

MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Wextra -g

SRCS = ./src/parse/p_attr.c \
		./src/parse/p_attr1.c \
		./src/parse/p_utils.c \
		./src/parse/p_utils1.c \
		./src/parse/p_file.c \
		./src/parse/p_main.c \
		./src/parse/p_map.c \
		./src/parse/p_multimap.c \
		./src/main.c  \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		./src/execute/exec1.c  \
		./src/execute/exec2.c \
		./src/execute/exec3.c \
		./src/execute/exec4.c \
		./src/execute/exec5.c \
		./src/execute/exec6.c \
		./src/execute/exec7.c \
		./src/execute/exec8.c \
		./src/execute/exec9.c \

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C mlx
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
clean:
	make clean -C mlx
	rm -rf $(OBJ)
	make -C libft clean
re: fclean all
.PHONY: all clean fclean re