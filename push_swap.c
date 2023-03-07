/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/06 19:38:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lsts(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp1;
	t_stack *temp2;
	temp1 = *stack_a;
	temp2 = *stack_b;
	if (temp1 != NULL && temp2 != NULL)
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

void	stack_init(t_stack **stack, char **list)
{
	int	i;
	struct s_stack *node;
	
	i = 1;
	while(list[i])
	{
		node = ft_lstnew(ft_atoi(list[i]));
		ft_lstadd_back(stack, node);
		i++;
	}
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *head_a;
	t_stack *head_b;
	
	head_a = *stack_a;
	head_b = *stack_b;
	temp = head_b;
	head_b = head_b->next;
	*stack_b = head_b;

	if (!head_a)
	{
		head_a = temp;
		head_a->next = NULL;
		*stack_a = head_a;
	}
	else
	{
		temp->next = head_a;
		*stack_a = temp;
	}
}

void	swap(t_stack **stack)
{
	t_stack *head;
	t_stack *temp;
	int i = 0;

	head = *stack;
	if(!head && !head->next)
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
	t_stack *head;
	t_stack *last;

	head = *stack;
	last = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
}

void	r_rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *last;

	head = *stack;
	last = ft_lstlast(head);
	*stack = last;
	last->next = head;
	while(head->data != 4)
	{
		head = head->next;
	}
	head->next = NULL;
	
}

void	pa (t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	pb (t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}

void	stack_free(t_stack **stack)
{
	t_stack *head;
	t_stack *temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (printf("Error\nNot enough arguments\n"));

	int i = 1;
	while(i < ac)
	{
		if(ft_atoi(av[i]) == 0)
			return (printf("Error\n"));
		i++;
	}
	
	t_stack **stack_a;
	t_stack **stack_b;
	
	stack_a = (t_stack**)malloc(sizeof(t_stack));
	stack_b = (t_stack**)malloc(sizeof(t_stack));
	
	*stack_a = NULL;
	*stack_b = NULL;

	stack_init(stack_a, av);
	
	print_lsts(stack_a, stack_b);
	
	/* pb(stack_a, stack_b);
	pb(stack_a, stack_b); */

	/* swap(stack_a); */

	/* rotate(stack_a); */

	r_rotate(stack_a);

	printf("\n");
	print_lsts(stack_a, stack_b);
	
	stack_free(stack_a);
	stack_free(stack_b);
	
	return (0);
}