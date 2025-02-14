# Comandos
RM = rm -f
CC = gcc

# Archivos y directorios
NAME = so_long
SRC = src/main.c src/render.c src/map.c src/events.c src/errors.c src/exit_page.c src/free.c src/parse_map.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = /minilibx-linux/mlx_init.h includes/so_long.h

# Colores
GREEN = \033[1;32m
RESET = \033[0m

# Reglas
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) minilibx-linux/libmlx.a -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	@echo "$(GREEN)Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)libft compilada!$(RESET)"

%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compilando $<...$(RESET)"
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "$(GREEN)$< compilado!$(RESET)"

clean:
	@echo "$(GREEN)Limpieza de so_long...$(RESET)"
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Limpieza completada.$(RESET)"

fclean: clean
	@echo "$(GREEN)Eliminando $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)$(NAME) eliminado.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
