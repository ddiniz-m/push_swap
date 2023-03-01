/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/01 14:28:11 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->data = data;
	node->next = NULL;
	return (node);
}

/* int main()
{
	int i;
	t_stack *temp;

	i = 0;
	char *str[4] = {"To", "The", "New", "World"};
	while((temp = ft_lstnew(str[i])) && i < 4)
	{
		printf("%s - ", temp->data);
		temp = temp->next;
		i++;
	}
	printf("\n");
} */