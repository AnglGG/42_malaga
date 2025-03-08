# Comandos
RM = rm -f
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

# Archivos
NAME = pipex
SRC = mandatory/pipex.c mandatory/utils.c mandatory/parse_path.c
OBJ = $(SRC:.c=.o)
INCLUDE = mandatory/pipex.h bonus/pipex_bonus.h

SRCS_BONUS = bonus/pipex_bonus.c bonus/utils_bonus.c bonus/here_doc_bonus.c bonus/execution_bonus.c bonus/error.c bonus/parse_path.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME_BONUS = pipex_bonus

# Colores
GREEN = \033[1;32m
RESET = \033[0m

$(NAME): $(OBJ)
	@echo "$(GREEN)Creating pipex...$(RESET)"
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) ../libft/libft.a
	@echo "$(GREEN)Pipex created: $(NAME)$(RESET)"

%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) -I. -c -o $@ $<
	@echo "$(GREEN)$< compiled!$(RESET)"


all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "$(GREEN)Creating pipex_bonus...$(RESET)"
	@$(CC) $(CCFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) ../libft/libft.a
	@echo "$(GREEN)Pipex_bonus created: $(NAME_BONUS)$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(RM) $(OBJ) $(OBJS_BONUS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME) $(NAME_BONUS)...$(RESET)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)Deleted $(NAME) $(NAME_BONUS)$(RESET)"

re: fclean all bonus

.PHONY: all bonus clean fclean re
