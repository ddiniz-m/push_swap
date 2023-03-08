/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/08 18:29:12 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **stack)
{
	int		i;
	int		j;
	t_stack	*temp;

	j = 1;
	i = j + 1;
	if(!*stack)
		return(-2);
	temp = *stack;
	while(temp)
	{
		if (!temp->next)
			break ;
		if(temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return(0);
}

int	get_min(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	
	temp = *stack;
	i = temp->data;
	while(temp)
	{
		if(temp->next && i > temp->next->data)
		{
			i = temp->next->data;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (i);
}

void	sort3(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next->next->data == get_min(stack_a))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a, 0);
		rra(stack_a, 0);
		return;
	}
	else if ((*stack_a)->next->data == get_min(stack_a))
	{
		if((*stack_a)->data < (*stack_a)->next->next->data)
			sa(stack_a, 0);
		else
			ra(stack_a, 0);
	}
	else
	{
		pb(stack_a, stack_b);
		sa(stack_a, 0);
		pa(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac == 1)
		return (printf("Error\nNot enough arguments\n"));
	if (check_list(ac, av) > 0)
		return (0);

	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;

	stack_init(stack_a, av);

	if(check_sort(stack_a) == 0)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (printf("Already sorted\n"));
	}

	printf("min = %i\n", get_min(stack_a));

	print_lsts(stack_a, stack_b);
	printf("\nInstructions:\n");
	
	if (ac == 4)
		sort3(stack_a, stack_b);
	
	printf("\n");
	print_lsts(stack_a, stack_b);
	
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
