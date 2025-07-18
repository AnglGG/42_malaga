LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft.h

BONUS			=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

PRINTF_SRC		= 	ft_printf.c ft_printf_utils.c ft_printf_hexadecimals.c \
					ft_printf_bonus.c ft_printf_bonus_2.c ft_numlen.c ft_putnbr.c

PRINTF_OBJS		= $(PRINTF_SRC:.c=.o)

# Colores
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Creating library...$(RESET)"
	@$(LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)Library created: $(NAME)$(RESET)"

bonus: $(OBJ) $(BONUS_OBJS) $(PRINTF_OBJS)
	@echo "$(GREEN)Creating bonus...$(RESET)"
	@$(LIB) $(NAME) $(OBJ) $(BONUS_OBJS) $(PRINTF_OBJS)
	@echo "$(GREEN)Bonus created!$(RESET)"

%.o: %.c $(INCLUDE)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) -c -o $@ $<
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(RM) $(OBJ) $(BONUS_OBJS) $(PRINTF_OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)Deleted $(NAME)$(RESET)"

re: fclean all bonus

.PHONY: all clean fclean bonus re