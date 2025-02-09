NAME = cub3D
LIBFT = libft/libft.a
CC = gcc

CFLAGS = -Wall -Werror -Wextra

# MLX_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = ./src/parse/p_attr.c \
		./src/parse/p_utils.c \
		./src/parse/p_utils1.c \
		./src/parse/p_file.c \
		./src/parse/p_main.c \
		./src/parse/p_map.c \
		./src/parse/p_multimap.c \
		./src/main.c  \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
    # make -C mlx
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	make clean # kaldirilacak
	
all: $(NAME)

fclean: clean
	rm -rf libft/*.a
	rm -rf get_next_line/*.a
	rm -rf $(NAME)
clean:
	# make clean -C mlx
	rm -rf $(OBJ)
	make fclean -C libft
	rm -rf get_next_line/*.o
re: fclean all
.PHONY: all clean fclean re