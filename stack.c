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

/* int	arr_size(char **list)
{
	int	i;

	i = 0;
	while(list[i])
		i++;
	return(i - 1);
}

void	arr_min(char **list, int n)
{
	int	i;
	int	k;
	int	size;

	i = 1;
	k = 1;
	size = arr_size(list);
	while (n < size && i < size)
	{
		if (ft_atoi(list[i + 1]) && ft_atoi(list[i]) < ft_atoi(list[i + 1]))
			k = i;
		i++;
	}
	list[k] = ft_itoa(n);
	return ;
}

void	ranking(char **list)
{
	int	i;
	int	n;
	int	size;

	i = 1;
	n = 0;
	size = arr_size(list);
	while(n <= size)
		arr_min(list, n++);
	while(list[i])
		printf("%i\n", ft_atoi(list[i++]));
	return ;
} */


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
