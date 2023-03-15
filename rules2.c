/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:54:42 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/15 14:31:38 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack, int i)
{
	rotate(stack);
	if (i != 1)
		ft_printf("ra\n");
}

void	rb(t_stack **stack, int i)
{
	rotate(stack);
	if (i != 1)
		ft_printf("sa\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	ft_printf("rr\n");
}
