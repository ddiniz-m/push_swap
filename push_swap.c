/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/03 18:55:12 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lsts(struct s_stack **head_a, struct s_stack **head_b)
{
	struct s_stack *temp1;
	struct s_stack *temp2;
	temp1 = *head_a;
	temp2 = *head_b;
	if (temp1 && temp2)
	{
		while (temp1 && temp2)
		{
			printf("%i %i\n",temp1->data, temp2->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	if (!temp2)
	{
		while(temp1)
		{
			printf("%i 0\n", temp1->data);
			temp1 = temp1->next;
		}
	}
	printf("- -\na b\n");
}

struct s_stack *stack_a(int len, char **list)
{
	int	i;
	struct s_stack *node;
	struct s_stack *head;
	
	i = 2;
	head = ft_lstnew(ft_atoi(list[1]));
	while(i <= len)
	{
		node = ft_lstnew(ft_atoi(list[i]));
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

struct s_stack *stack_b(int len)
{
	int	i;
	struct s_stack *node;
	struct s_stack *head;
	
	i = 2;
	head = ft_lstnew(0);
	while(i <= len)
	{
		node = ft_lstnew(0);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

void	del(int i)
{
	i = 0;
}

void	pa(t_stack **head_a, t_stack **head_b)
{
	struct s_stack *temp1;
	struct s_stack *temp2;
	
	temp1 = *head_a;
	temp2 = *head_b;
	
	int i = 0;
	while(1)
	{
		if (temp1->data != 0)
		{
			temp1 = temp1->next;
			(temp1 + i++)->data = temp1->data;
		}
		else
		{
			temp1->data = temp2->data;
			break;
		}
	}
	*head_b = (*head_b)->next;
}

/* void	pb(t_stack **head_a, t_stack **head_b)
{
	struct s_stack *temp1;
	struct s_stack *temp2;
	
	ft_lstadd_front(head_b, ft_lstnew(0));
	temp1 = *head_a;
	temp2 = *head_b;
	
	temp2->data = temp1->data;
	*head_a = (*head_a)->next;
	ft_lstadd_back(head_a, ft_lstnew(0));
} */

int	main(int ac, char **av)
{
	if (ac == 1)
		return (printf("Error\nNot enough arguments\n"));

	struct s_stack *head_a;
	struct s_stack *head_b;
	
	int i = 1;
	while(i < ac)
	{
		if(ft_atoi(av[i]) == 0)
			return (printf("Error\n"));
		i++;
	}
	head_a = stack_b(ac - 1);
	head_b = stack_a(ac - 1, av);
	
	print_lsts(&head_a, &head_b);
	
	/* if (head_a)
	{
		int i = 0;
		while (i++ < 5)
			pb(&head_a, &head_b);
	} */
	
	if (head_b)
	{
		int i = 0;
		while (i++ < 2)
			pa(&head_a, &head_b);
	}

	printf("\n");
	print_lsts(&head_a, &head_b);
	return (0);
}