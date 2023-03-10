/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:53:38 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/10 15:20:12 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack, int i)
{
	t_stack *temp;

	temp = *stack;
	if (ft_lstsize(stack) <= 1)
		return ;
	swap(stack);
	if (i != 1)
		printf("sa\n");
}

void	sb(t_stack **stack, int i)
{
	t_stack *temp;

	temp = *stack;
	if (ft_lstsize(stack) <= 1)
		return ;
	swap(stack);
	if (i != 1)
		printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	push(stack_a, stack_b);
	printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	push(stack_b, stack_a);
	printf("pb\n");
}
