/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:28:24 by marvin            #+#    #+#             */
/*   Updated: 2023/03/14 18:28:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack **stack, char **list)
{
	int				i;
	struct s_stack	*node;

	i = 1;
	while (list[i])
	{
		node = ft_lstnew(ft_atoi(list[i]));
		ft_lstadd_back(stack, node);
		i++;
	}
}

void	stack_free(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}
