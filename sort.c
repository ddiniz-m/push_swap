/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:42:17 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/14 18:42:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//Brute force, if smallest number is in pos 1, 2 or 3.
void	sort3(t_stack **stack_a, t_stack **stack_b)
{
	if (min_pos(stack_a) == 1)
	{
		pb(stack_a, stack_b);
		sa(stack_a, 0);
		pa(stack_a, stack_b);
	}
	else if (min_pos(stack_a) == 2)
	{
		if((*stack_a)->data < (*stack_a)->next->next->data)
			sa(stack_a, 0);
		else
			ra(stack_a, 0);
	}
	else
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a, 0);
		rra(stack_a, 0);
		return;
	}
}

// Get smallest number to top and puts it in b. Two times.
// Then sort3 and puts the two smallest numbers back in a.
void	sort5(t_stack** stack_a, t_stack** stack_b)
{
	while(ft_lstsize(stack_a) != 3)
	{
		if(min_pos(stack_a) <= 3)
		{
			while((*stack_a)->data != get_min(stack_a))
				ra(stack_a, 0);
		}
		else
			while((*stack_a)->data != get_min(stack_a))
				rra(stack_a, 0);
		if (check_sort(stack_a) == 0)
			return ;
		pb(stack_a, stack_b);
	}
	sort3(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	j;
	int	maxbits;
	
	i = 1;
	j = 0;
	maxbits = digits(get_max((stack_a)));
	stack_a = stack_to_binary(stack_a);
	while (i <= maxbits)
	{
		while(j < size)
		{
			if(i > digits((*stack_a)->data) || (*stack_a)->data % ft_power(10, i) / ft_power(10, i - 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, 0);
			j++;
		}
		while(*stack_b)
			pa(stack_a, stack_b);
		i++;
		j = 0;
	}
}

int	sort(t_stack **stack_a, t_stack** stack_b, int ac)
{
	int	i;

	if(check_sort(stack_a) == 0)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (printf("Already sorted\n"));
	}
	i = ft_lstsize(stack_a);
	if (ac == 4)
		sort3(stack_a, stack_b);
	if (ac == 5 || ac == 6)
		sort5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, i);
	return (0);
}
