# - * - Makefile - * -

PRT_SRC = ft_printf/ft_printf.c  ft_printf/ft_check.c ft_printf/ft_puthexa.c\
		ft_printf/utils.c

SRC_LIB = libft/ft_atoi.c libft/ft_lstnew.c libft/ft_lstadd_back.c\
		libft/ft_lstlast.c libft/ft_lstsize.c libft/ft_strcmp.c

SRCS = push_swap.c rulesRaw.c rules1.c rules2.c rules3.c utils.c sort.c\
		check.c binary.c stack.c $(SRC_LIB) $(PRT_SRC)

OBJS = $(SRCS:%.c=%.o)
NAME = push_swap
CC = @gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME)

run: $(NAME)
		@./push_swap 3 8 6 4 5 0 9

val: $(NAME)
		@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap 1 2 3 4 5 6 7 8 9 10

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re run val