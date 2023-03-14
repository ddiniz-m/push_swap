/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:41:03 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/14 18:29:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_to_binary(int num)
{
	int	i;
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

int	array_to_int(int *arr, int size)
{
	int	i;
	int	buf;

	buf = 0;
	i = size - 1;
	while (i >= 0)
	{	
		buf = (10 * buf) + arr[i];
		i--;
	}
	return(buf);
}

t_stack	**stack_to_binary(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	(*stack)->data = array_to_int(int_to_binary((*stack)->data), digits((*stack)->data));
	rotate(stack);
	while((*stack)->data != temp->data)
	{
		(*stack)->data = array_to_int(int_to_binary((*stack)->data), digits((*stack)->data));
		rotate(stack);
	}
	return(stack);
}