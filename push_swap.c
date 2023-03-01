/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/01 17:53:03 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lsts(struct s_stack *head1, struct s_stack *head2)
{
	struct s_stack *temp1;
	struct s_stack *temp2;
	temp1 = head1;
	temp2 = head2;
	while (temp1 != NULL)
	{
		printf("%i %i\n",temp1->data, temp2->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
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
	while(i <=len)
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
	head = ft_lstnew(5);
	while(i <=len)
	{
		node = ft_lstnew(0);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

void	pa(t_stack *head_a, t_stack *head_b)
{
	ft_lstadd_front(&head_a, head_b);
}

void	pop()
{
	;
}

void	del(int i)
{
	i = 0;
}

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
	head_a = stack_a(ac - 1, av);
	head_b = stack_b(ac);
	print_lsts(head_a, head_b);
	
	pa(head_a, head_b);
	
	/* ft_lstclear(&head_a, del); */
	printf("\n");
	print_lsts(head_a, head_b);
	return (0);
}