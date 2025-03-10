LIB = ar rcs
RM = rm -f

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

USER		= anggalle
SRC_DIR		= ./srcs/

COMMANDS_DIR	=	$(SRC_DIR)commands/push.c \
			$(SRC_DIR)commands/rev_rotate.c \
			$(SRC_DIR)commands/rotate.c \
			$(SRC_DIR)commands/sort_stacks.c \
			$(SRC_DIR)commands/sort_three.c \
			$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR	=	$(SRC_DIR)push_swap/handle_errors.c \
			$(SRC_DIR)push_swap/init_a_to_b.c \
			$(SRC_DIR)push_swap/init_b_to_a.c \
			$(SRC_DIR)push_swap/push_swap.c \
			$(SRC_DIR)push_swap/stack_init.c \
			$(SRC_DIR)push_swap/stack_utils.c

CHECKER_DIR	=	checker_bonus/checker.c \
			$(SRC_DIR)push_swap/handle_errors.c \
			$(SRC_DIR)push_swap/stack_init.c \
			$(SRC_DIR)push_swap/stack_utils.c \
			$(SRC_DIR)push_swap/init_a_to_b.c \
			$(SRC_DIR)push_swap/init_b_to_a.c

SRCS_PUSH_SWAP = $(COMMANDS_DIR) $(PUSH_SWAP_DIR)
SRCS_CHECKER	= $(COMMANDS_DIR) $(CHECKER_DIR) 

OBJS_PUSH_SWAP	= $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER	= $(SRCS_CHECKER:.c=.o)

INCLUDES	= -I ./libft -I ./printf
LIBFT		= libft/libft.a
PRINTF		= printf/libftprintf.a
LIBS		= -L./libft -lft -L./printf -lftprintf

NAME		= push_swap
CHECKER		= checker

# Colores
GREEN		= \033[1;32m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS_PUSH_SWAP)
	@echo "$(GREEN)Compiling objects...$(RESET)"
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./printf
	@$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"

$(CHECKER): $(OBJS_CHECKER)
	@echo "$(GREEN)Compiling checker...$(RESET)"
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./printf
	@$(CC) $(CFLAGS) $(OBJS_CHECKER) $(LIBS) -o $(CHECKER)
	@echo "$(GREEN)Executable created: $(CHECKER)$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./printf clean
	@$(RM) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME) and $(CHECKER)...$(RESET)"
	@$(MAKE) -C ./libft fclean
	@$(MAKE) -C ./printf fclean
	@$(RM) $(NAME) $(CHECKER)
	@echo "$(GREEN)Deleted $(NAME) and $(CHECKER)$(RESET)"

re: fclean all

.PHONY: all clean fclean re checker
