/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:21:44 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/22 18:11:36 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(int ac, char **av)
{
	int	i;

	i = 1;
	if (check_dups(ac, av) != 0)
		return (1);
	while (i <= ac - 1)
	{
		if (ft_strcmp(av[i], "0") == 0)
			i++;
		else
		{
			if (ft_atoi(av[i]) == 0)
				return (write(2, "Error\n", 7));
			i++;
		}
	}
	return (0);
}

int	check_dups(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	i = j + 1;
	while (j < ac - 1)
	{
		while (i < ac)
		{
			if (ft_strcmp(av[j], av[i]) == 0)
				return (write(2, "Error\n", 7));
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

int	check_sort(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return (-2);
	temp = *stack;
	while (temp)
	{
		if (!temp->next)
			break ;
		if (temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
