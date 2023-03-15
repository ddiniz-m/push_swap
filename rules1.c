/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:53:38 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/15 14:31:30 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack, int i)
{
	if (ft_lstsize(stack) <= 1)
		return ;
	swap(stack);
	if (i != 1)
		ft_printf("sa\n");
}

void	sb(t_stack **stack, int i)
{
	if (ft_lstsize(stack) <= 1)
		return ;
	swap(stack);
	if (i != 1)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
