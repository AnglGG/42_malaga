# Comandos
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Archivos y directorios
NAME = so_long
SRC = src/main.c src/render.c src/map.c src/events.c src/errors.c src/exit_page.c src/free.c src/parse_map.c src/parse_map_2.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
INCLUDE = $(MLX_DIR)/mlx.h/mlx_init.h includes/so_long.h

# Colores
GREEN = \033[1;32m
RESET = \033[0m

# Reglas
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "$(GREEN)Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)$(NAME) compilado!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Compilando libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "$(GREEN)libft compilada!$(RESET)"

$(MLX):
	@echo "$(GREEN)Compilando MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "$(GREEN)MinilibX compilada!$(RESET)"

%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compilando $<...$(RESET)"
	@$(CC) -s $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@
	@echo "$(GREEN)$< compilado!$(RESET)"

clean:
	@echo "$(GREEN)Limpieza de so_long...$(RESET)"
	@$(RM) $(OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@echo "$(GREEN)Limpieza completada.$(RESET)"

fclean: clean
	@echo "$(GREEN)Eliminando $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@echo "$(GREEN)$(NAME) eliminado.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
