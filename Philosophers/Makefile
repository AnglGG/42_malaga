NAME = philo
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -pthread

SRCDIR = src
INCDIR = include
LIBFTDIR = libft

SRC =	main.c parsing.c error.c utils.c init.c cleanup.c \
		print.c simulation.c philosopher.c monitor.c \
		utils_time.c philosopher_utils.c simulation_utils.c

SRCFILES = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(SRCFILES:.c=.o)
INCLUDE = $(INCDIR)/philo.h $(LIBFTDIR)/libft.h

# Colores
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Creating executable...$(RESET)"
	@make bonus -C $(LIBFTDIR)
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"

%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c -o $@ $<
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(RM) $(OBJ)
	@make clean -C $(LIBFTDIR)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "$(GREEN)Deleted $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re 