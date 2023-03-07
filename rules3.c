/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:33 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/07 15:35:26 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack, int i)
{
	r_rotate(stack);
	if (i != 1)
		printf("rra\n");
}

void	rrb(t_stack **stack, int i)
{
	r_rotate(stack);
	if (i != 1)
		printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	printf("rrr\n");
}