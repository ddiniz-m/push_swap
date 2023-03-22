/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:44:41 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/22 14:16:00 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (temp)
	{
		if (temp->next && i > temp->next->data)
		{
			i = temp->next->data;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (i);
}
