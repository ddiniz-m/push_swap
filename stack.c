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

void	free_all(t_stack **stack_a, t_stack **stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
}

void	index_to_data(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		temp->data = temp->index;
		temp = temp->next;
	}
}

void	ranking(t_stack **stack)
{
	int		i;
	t_stack	*temp1;
	t_stack	*temp2;

	i = 0;
	temp1 = *stack;
	temp2 = temp1->next;
	while (temp1)
	{
		if (temp1->data > temp2->data)
			i++;
		temp2 = temp2->next;
		if (!temp2)
		{
			temp1->index = i;
			temp1 = temp1->next;
			temp2 = *stack;
			i = 0;
		}
	}
	index_to_data(stack);
}

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
