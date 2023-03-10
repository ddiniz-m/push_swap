/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:42:17 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/10 18:47:47 by ddiniz-m         ###   ########.fr       */
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

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	tmp = *stack_a;
	int	i = ft_lstsize(stack_a);
	while(*stack_a)
	{
		if (min_pos(stack_a) >= i / 2)
		{
			while((*stack_a)->data != get_min(stack_a))
			rra(stack_a, 0);
		}
		else
			while((*stack_a)->data != get_min(stack_a))
			ra(stack_a, 0);
		pb(stack_a, stack_b);
	}
	while(*stack_b)
		pa(stack_a, stack_b);
}
		/* printf("-------\n");
		print_lsts(&tmp, stack_b);
		printf("-------\n\n"); */
