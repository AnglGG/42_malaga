LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC =	pipex.c

OBJ = $(SRC:.c=.o)
INCLUDE = ft_pipex.h

BONUS			=	ft_printf_bonus.c ft_printf_bonus_2.c

BONUS_OBJS		= $(BONUS:.c=.o)

# Colores
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Creating library...$(RESET)"
	@$(LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)Library created: $(NAME)$(RESET)"

bonus: $(OBJ) $(BONUS_OBJS)
	@echo "$(GREEN)Creating bonus...$(RESET)"
	@$(LIB) $(NAME) $(OBJ) $(BONUS_OBJS)
	@echo "$(GREEN)Bonus created!$(RESET)"

%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) -c -o $@ $<
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(RM) $(OBJ) $(BONUS_OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)Deleted $(NAME)$(RESET)"

re: fclean all bonus

.PHONY: all clean fclean bonus re