/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:41:03 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/15 18:11:35 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_to_binary(int num)
{
	int			i;
	static int	binary[32];

	i = 0;
	if (num == 0)
		binary[0] = 0;
	while (num != 0)
	{
		binary[i++] = num % 2;
		num /= 2;
	}
	return (binary);
}

int	digits(int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num /= 2;
		i++;
	}
	return (i);
}

//check if number in position i is 0 or 1
int	test(int num, int i)
{
	int	j;
	int	buf;

	j = 0;
	buf = num;
	if (i == 0)
	{
		if (buf % 2 == 0)
			return (0);
		if (buf % 2 == 1)
			return (1);
	}
	while(j < i)
	{
		buf /= 2;
		j++;
	}
	if (buf % 2 == 0)
		return (0);
	if (buf % 2 == 1)
		return (1);
	return 0;
}

/* t_stack	**stack_to_binary(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	(*stack)->data = array_to_int(int_to_binary((*stack)->data), digits((*stack)->data));
	rotate(stack);
	while ((*stack)->data != temp->data)
	{
		(*stack)->data = array_to_int(int_to_binary((*stack)->data), digits((*stack)->data));
		rotate(stack);
	}
	return (stack);
} */
