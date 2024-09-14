LIB = ar rcs
RM = rm -f

CC = clang
CFLAGS = -Wall -Werror -Wextra

USER		= paromero
SRCS		= src/main.c src/args.c src/errors.c src/utils.c src/push.c src/swap.c src/rotate.c src/reverse_rotate.c src/three_algorithm.c src/sorting.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I ./libft
LIBFT		= libft/libft.a
LIBS		= -L./libft -lft

NAME = push_swap

# Colores
#
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling objects...$(RESET)"
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME)...$(RESET)"
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)
	@echo "$(GREEN)Deleted $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re