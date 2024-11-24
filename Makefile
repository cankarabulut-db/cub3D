NAME = cub3D
SRC = main.c map.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

RESET=\033[0m
RED=\033[31m
LIGHT_RED=\033[91m
GREEN=\033[32m
LIGHT_GREEN=\033[92m
YELLOW=\033[33m
LIGHT_YELLOW=\033[93m
BLUE=\033[34m
LIGHT_BLUE=\033[94m
MAGENTA=\033[35m
LIGHT_MAGENTA=\033[95m
CYAN=\033[36m
LIGHT_CYAN=\033[96m
WHITE=\033[37m
GREY=\033[90m
LIGHT_GREY=\033[37m

all : $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Compailing include please wait$(GREEN)"
	@make -C libft | awk '{printf "."; fflush()}'
	@echo ""
	@echo "$(YELLOW)Compailing main proje please wait$(GREEN)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN).$(RESET)" | tr -d '\n'

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) $(LIBFT) $(SRC) -o $(NAME)
	@clear
	@echo "$(GREEN)"
	@echo "Cube3D Compiled"
	@echo "$(RESET)"
	
clean:
	@clear
	@$(RM) $(OBJ)
	@make -C libft clean
	@echo "$(CYAN)Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo "$(CYAN)Readline files removed$(RESET)"
	@clear

re: fclean all
.PHONY: all clean fclean re