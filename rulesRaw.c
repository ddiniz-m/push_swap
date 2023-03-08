/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rulesRaw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:51:33 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/08 13:44:46 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*temp;
	t_stack	*head_dest;
	t_stack	*head_src;

	head_dest = *stack_dest;
	head_src = *stack_src;
	temp = head_src;
	head_src = head_src->next;
	*stack_src = head_src;
	if (!head_dest)
	{
		head_dest = temp;
		head_dest->next = NULL;
		*stack_dest = head_dest;
	}
	else
	{
		temp->next = head_dest;
		*stack_dest = temp;
	}
}

void	swap(t_stack **stack)
{
	int		i;
	t_stack	*head;
	t_stack	*temp;

	i = 0;
	head = *stack;
	if (!head && !head->next)
	{
		printf("Error\n");
		return ;
	}
	temp = head;
	i = temp->data;
	head->data = head->next->data;
	head->next->data = i;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack) == 0)
		return ;
	head = *stack;
	last = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
}

void	r_rotate(t_stack **stack)
{
	int		i;
	int		j;
	t_stack	*head;
	t_stack	*last;

	i = 0;
	j = ft_lstsize(*stack);
	if (!*stack)
		return ;
	head = *stack;
	last = ft_lstlast(head);
	*stack = last;
	last->next = head;
	while (i < j - 2)
	{
		head = head->next;
		i++;
	}
	head->next = NULL;
}
