/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:42:17 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/13 19:52:34 by ddiniz-m         ###   ########.fr       */
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

t_stack	**stack_to_binary(t_stack **stack)
{
	int	size;
	t_stack *temp;

	temp = *stack;
	size = binary_size((*stack)->data);
	(*stack)->data = array_to_int(int_to_binary((*stack)->data), size);
	rotate(stack);
	while((*stack)->data != temp->data)
	{
		size = binary_size((*stack)->data);
		(*stack)->data = array_to_int(int_to_binary((*stack)->data), size);
		rotate(stack);
	}
	return(stack);
}

int	get_max_int(t_stack **stack)
{
	int	i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while(temp)
	{
		if (temp->data > i)
			i = temp->data;
		temp = temp->next;
	}
	return(i);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	j;
	int	maxbits;
	int	minbits;
	
	i = 1;
	j = 0;
	printf("-------\n");
	print_lsts(stack_a, stack_b);
	printf("-------\n\n");
	maxbits = binary_size(get_max_int((stack_a)));
	minbits = binary_size(get_min(stack_a));
	stack_a = stack_to_binary(stack_a);
	printf("-------\n");
	print_lsts(stack_a, stack_b);
	printf("-------\n\n");
	while (i <= maxbits)
	{
		while(j <= size)
		{
			if(i > binary_size((*stack_a)->data) || (*stack_a)->data % ft_power(10, i) / ft_power(10, i - 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, 0);
			j++;
		}
		printf("-------\n");
		print_lsts(stack_a, stack_b);
		printf("-------\n\n");
		if (check_sort(stack_a) == 0 && !*stack_b)
			return ;
		else
		{
			while(*stack_b)
				pa(stack_a, stack_b);
		}
		i++;
		j = 0;
	}
}

		/* printf("-------\n");
		print_lsts(&tmp, stack_b);
		printf("-------\n\n"); */