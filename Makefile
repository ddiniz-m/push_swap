# - * - Makefile - * -

SRC_LIB = libft/ft_atoi.c libft/ft_lstnew.c libft/ft_lstadd_back.c\
		libft/ft_lstlast.c libft/ft_lstadd_front.c libft/ft_lstclear.c\
		libft/ft_lstdelone.c libft/ft_lstsize.c libft/ft_strcmp.c

SRCS = push_swap.c rulesRaw.c rules1.c rules2.c rules3.c utils.c $(SRC_LIB)

OBJS = $(SRCS:%.c=%.o)
NAME = push_swap
CC = @cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME)

run: $(NAME)
	@./push_swap 3 2 1

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
