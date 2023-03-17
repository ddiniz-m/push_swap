/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:05:44 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/17 18:27:02 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

//--------------------------------PUSH_SWAP-----------------------------------
void				push(t_stack **stack_a, t_stack **stack_b);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				r_rotate(t_stack **stack);

void				printlist(t_stack **stack);

void				stack_init(t_stack **stack, char **list);
void				stack_free(t_stack **stack);
void				ranking(char **list);
int					check_list(int ac, char **av);
int					check_dups(int ac, char **av);
int					check_sort(t_stack **stack);
int					min_pos(t_stack **stack);
int					get_max(t_stack **stack);
int					get_min(t_stack **stack);

int					*int_to_binary(int num);
int					digits(int num);
int					zero_or_one(int num, int i);
t_stack				**stack_to_binary(t_stack **stack);
int					ft_power(int nb, int power);
void				print_list(t_stack **stack);

int					sort(t_stack **stack_a, t_stack **stack_b, int ac);
void				radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

void				sa(t_stack **stack, int i);
void				sb(t_stack **stack, int i);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack, int i);
void				rb(t_stack **stack, int i);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack, int i);
void				rrb(t_stack **stack, int i);
void				rrr(t_stack **stack_a, t_stack **stack_b);
//----------------------------------LIBFT-------------------------------------
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_strcmp(char *s1, char *s2);
t_stack				*ft_lstnew(int data);
int					ft_recursive_power(int nb, int power);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack **lst);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstdelone(t_stack *lst, void (*del)(int));
void				ft_lstclear(t_stack **lst, void (*del)(int));
void				ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack				*ft_lstmap(t_stack *lst, void *(*f)(void *),
						void (*del)(void *));
//----------------------------------PRINTF-------------------------------------
int					ft_printf(const char *str, ...);
int					ft_puthexa(unsigned long long nbr,
						unsigned long long base, int i);
int					ft_check(char str, va_list args);
int					ft_putstr(char *str);
int					ft_putchar(char c);
int					ft_putnbr(int nb);
int					ft_putptr(unsigned long nbr);

#endif