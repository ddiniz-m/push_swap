/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/16 17:58:48 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac == 1)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (check_list(ac, av) > 0)
		return (0);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_init(stack_a, av);
	if (check_sort(stack_a) == 0)
		return (0);
	sort(stack_a, stack_b, ac);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
