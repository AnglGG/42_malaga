# Comandos
RM = rm -f
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

# Archivos
NAME = pipex
SRC = src/mandatory/pipex.c src/mandatory/utils.c src/mandatory/parse_path.c
OBJ = $(SRC:.c=.o)
INCLUDE = mandatory/pipex.h bonus/pipex_bonus.h

SRCS_BONUS = src/bonus/pipex_bonus.c src/bonus/utils_bonus.c src/bonus/here_doc_bonus.c src/bonus/execution_bonus.c src/bonus/error.c src/bonus/parse_path.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME_BONUS = pipex_bonus

# Colores
GREEN = \033[1;32m
RESET = \033[0m

# Ruta libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compilar libft antes de pipex
$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

# Compilar pipex
$(NAME): $(LIBFT) $(OBJ)
	@echo "$(GREEN)Creating pipex...$(RESET)"
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN)Pipex created: $(NAME)$(RESET)"

# Compilar archivos .c a .o
%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) -I. -c -o $@ $<
	@echo "$(GREEN)$< compiled!$(RESET)"

# Crear todo
all: $(NAME) $(NAME_BONUS)

# Compilar bonus
bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "$(GREEN)Creating pipex_bonus...$(RESET)"
	@$(CC) $(CCFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)
	@echo "$(GREEN)Pipex_bonus created: $(NAME_BONUS)$(RESET)"

# Limpiar archivos objeto
clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(RM) $(OBJ) $(OBJS_BONUS)
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Clean complete.$(RESET)"

# Eliminar archivos ejecutables
fclean: clean
	@echo "$(GREEN)Deleting $(NAME) $(NAME_BONUS)...$(RESET)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Deleted $(NAME) $(NAME_BONUS)$(RESET)"

# Recompliar todo desde cero
re: fclean all

.PHONY: all bonus clean fclean re
