# - * - Makefile - * -

SRC_LIB = libft/ft_atoi.c libft/ft_lstnew.c libft/ft_lstadd_back.c\
		libft/ft_lstlast.c libft/ft_lstadd_front.c libft/ft_lstclear.c\
		libft/ft_lstdelone.c libft/ft_lstsize.c libft/ft_strcmp.c\
		libft/ft_power.c

SRCS = push_swap.c rulesRaw.c rules1.c rules2.c rules3.c utils.c sort.c\
		utils2.c bits.c $(SRC_LIB)

OBJS = $(SRCS:%.c=%.o)
NAME = push_swap
CC = @cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME)

run: $(NAME)
		@./push_swap 6 24 56 95 10 89 93 60 11 77
		
#98 91 87 44 99 32 33 38 \
		69 20 72 42 76 48 53 46 45 82 3 57 49 47 39 68 43 34 88 58 37 9 73 \
		4 81 17 30 2 75 15 94 27 18 70 84 92 83 23 74 5 21 13 64 1 90 7 22 71 \
		79 8 52 85 55 67 28 66 59 80 86 54 78 19 26 62 97 50 41 35 31 25 36 100 \
		12 63 29 14 96 40 61 51 16 65

val: $(NAME)
		@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap \
	95 24 56 6 10 89 93 60 11 77 98 91 87 44 99 32 33 38 \
	69 20 72 42 76 48 53 46 45 82 3 57 49 47 39 68 43 34 88 58 37 9 73 \
	4 81 17 30 2 75 15 94 27 18 70 84 92 83 23 74 5 21 13 64 1 90 7 22 71 \
	79 8 52 85 55 67 28 66 59 80 86 54 78 19 26 62 97 50 41 35 31 25 36 100 \
	12 63 29 14 96 40 61 51 16 65
clean:
		@$(RM) $(OBJS) 

fclean: clean
		@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re run val
