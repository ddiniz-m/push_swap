/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/13 19:56:04 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	printf("test1 = %i\n", array_to_int(int_to_binary(6), binary_size(6)));
	printf("test2 = %i\n", array_to_int(int_to_binary(11), binary_size(11)));
	printf("test3 = %i\n", binary_size(11));

	int	i = ft_lstsize(stack_a);
	if (ac == 4)
		sort3(stack_a, stack_b);
	if (ac == 5 || ac == 6)
		sort5(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, i);

	printf("Correct result:\n110\n1010\n1011\n11000\n111000\n111100\n1001101\n1011001\n1011101\n1011111\n");
	
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
