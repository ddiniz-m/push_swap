/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:05:44 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/22 18:13:22 by ddiniz-m         ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
}					t_stack;

//--------------------------------PUSH_SWAP-----------------------------------

void				stack_init(t_stack **stack, char **list);
void				stack_free(t_stack **stack);
void				free_all(t_stack **stack_a, t_stack **stack_b);
void				ranking(t_stack **stack);
void				index_to_data(t_stack **stack);
int					check_list(int ac, char **av);
int					check_sort(t_stack **stack);
int					check_dups(int ac, char **av);
int					min_pos(t_stack **stack);
int					get_min(t_stack **stack);
int					digits(int num);
int					zero_or_one(int num, int i);
int					sort(t_stack **stack_a, t_stack **stack_b, int ac);
void				radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

void				push(t_stack **stack_a, t_stack **stack_b);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				r_rotate(t_stack **stack);
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
int					ft_atoi(const char *str);
int					ft_strcmp(char *s1, char *s2);
t_stack				*ft_lstnew(int data);
int					ft_lstsize(t_stack **lst);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
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