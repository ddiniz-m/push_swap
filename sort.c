/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:42:17 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/22 14:37:23 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Brute force, if smallest number is in pos 1, 2 or 3.
void	sort3(t_stack **stack_a)
{
	if (min_pos(stack_a) == 1)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
		return ;
	}
	if (min_pos(stack_a) == 2)
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data)
			sa(stack_a, 0);
		else
			ra(stack_a, 0);
		return ;
	}
	if (min_pos(stack_a) == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a, 0);
		rra(stack_a, 0);
		return ;
	}
}

// Get smallest number to top and puts it in b. Two times.
// Then sort3 and puts the two smallest numbers back in a.
void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(stack_a) != 3)
	{
		if (min_pos(stack_a) <= 3)
		{
			while ((*stack_a)->data != get_min(stack_a))
				ra(stack_a, 0);
		}
		else
			while ((*stack_a)->data != get_min(stack_a))
				rra(stack_a, 0);
		if (check_sort(stack_a) == 0)
			return ;
		pb(stack_a, stack_b);
	}
	sort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

// i representes the position of the digit under inspection
//checks "i" binary digit of each number in the stack.
//If that number is 0 sends number to stack_b (pb)
//If that number is 1 sends number to end of stack_a (ra)
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	j;

	i = 0;
	while (check_sort(stack_a) != 0)
	{
		j = 1;
		while (j <= size)
		{
			if (i > digits((*stack_a)->data)
				|| zero_or_one(((*stack_a)->data), i) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, 0);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

int	sort(t_stack **stack_a, t_stack **stack_b, int ac)
{
	int	i;

	i = ft_lstsize(stack_a);
	if (ac == 3)
		sa(stack_a, 0);
	if (ac == 4)
		sort3(stack_a);
	if (ac == 5 || ac == 6)
		sort5(stack_a, stack_b);
	if (ac >= 7)
		radix_sort(stack_a, stack_b, i);
	return (0);
}
