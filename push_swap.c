/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:04:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/28 17:57:17 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void	print_lst(struct s_stack *head)
{
	struct s_stack *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%i\n",temp->data);
		temp = temp->next;
	}	
}

struct s_stack *list_init(char **list)
{
	int	i;
	struct s_stack *head;

	head = NULL;
	i = 1;
	head = malloc(sizeof(t_stack));
	head->data = ft_atoi(list[i]);
	head->next = NULL;
	return (head);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (printf("Error\nNot enough arguments\n"));
	print_lst(list_init(av));
	return (0);
}