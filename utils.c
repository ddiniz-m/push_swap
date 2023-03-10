/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:21:44 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/10 15:43:16 by ddiniz-m         ###   ########.fr       */
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
				return (printf("Error\nArgument not an integer\n"));
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
				return (printf("Error\nThere are duplicate arguments\n"));
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

void	print_lsts(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *stack_a;
	temp2 = *stack_b;
	/* if (!temp2)
	{
		while (temp1)
		{
			printf("%i\n", temp1->data);
			temp1 = temp1->next;
		}
		return ;
	} */
	/* int i = 0; */
	while (temp1 || temp2)
	{
		if(!temp1 && temp2)
		{
			printf("  %i\n",temp2->data);
			temp2 = temp2->next;
		}
		if(!temp2 && temp1)
		{
			printf("%i  \n",temp1->data);
			temp1 = temp1->next;
		}
		else if (temp1 && temp2)
		{
			printf("%i %i\n", temp1->data, temp2->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	printf("- -\na b\n");
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
