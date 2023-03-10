/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:44:41 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/10 15:56:48 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **stack)
{
	int		i;
	int		j;
	t_stack	*temp;

	j = 1;
	i = j + 1;
	if(!*stack)
		return(-2);
	temp = *stack;
	while(temp)
	{
		if (!temp->next)
			break ;
		if(temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return(0);
}

int	min_pos(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = *stack;
	while (temp)
	{
		if (temp->data == get_min(stack))
			return (i);
		i++;
		temp = temp->next;
	}
	return (0);
}

int	get_min(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	
	temp = *stack;
	i = temp->data;
	while(temp)
	{
		if(temp->next && i > temp->next->data)
		{
			i = temp->next->data;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (i);
}
