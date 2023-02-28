# - * - Makefile - * -

SRCS = push_swap.c ft_atoi.c

OBJS = $(SRCS:%.c=%.o)
NAME = push_swap
CC = @cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
