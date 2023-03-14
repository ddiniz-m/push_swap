/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:10 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/07 15:20:24 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

/* int main()
{
	int i;
	t_stack *temp;
	t_stack *head;

	i = 0;
	char *str[4] = {"To", "The", "New", "World"};
	head = ft_lstnew(str[i++]);
	while(i < 4)
	{
		ft_lstadd_front(&head, ft_lstnew(str[i]));
		i++;
	}
	temp = head;
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
} */