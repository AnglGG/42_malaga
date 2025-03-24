# Commands
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Files and directories
NAME = so_long
SRC = src/main.c src/render.c src/map.c src/events.c src/errors.c src/exit_page.c src/free.c src/parse_map.c src/parse_map_2.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
INCLUDE = $(MLX_DIR)/mlx.h/mlx_init.h includes/so_long.h

# Colors
GREEN = \033[1;32m
RESET = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "$(GREEN)libft compiled!$(RESET)"

$(MLX):
	@echo "$(GREEN)Compiling MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "$(GREEN)MinilibX compiled!$(RESET)"

%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) -s $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning so_long...$(RESET)"
	@$(RM) $(OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@echo "$(GREEN)Cleaning completed.$(RESET)"

fclean: clean
	@echo "$(GREEN)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@echo "$(GREEN)$(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
