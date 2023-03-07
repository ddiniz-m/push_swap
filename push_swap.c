/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/07 16:40:02 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (printf("Error\nNot enough arguments\n"));
	if (check_list(ac, av) > 0)
		return (0);
	
	t_stack **stack_a;
	t_stack **stack_b;
	
	stack_a = (t_stack**)malloc(sizeof(t_stack));
	stack_b = (t_stack**)malloc(sizeof(t_stack));
	
	*stack_a = NULL;
	*stack_b = NULL;

	stack_init(stack_a, av);
	
	print_lsts(stack_a, stack_b);

	/* printf("\n");
	print_lsts(stack_a, stack_b); */
	
	stack_free(stack_a);
	stack_free(stack_b);
	
	return (0);
}