/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:28 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/28 17:17:23 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int main()
{
	int i;
	t_list *temp;

	i = 0;
	char *str[4] = {"To", "The", "New", "World"};
	while((temp = ft_lstnew(str[i])) && i < 4)
	{
		printf("%s - ", temp->content);
		temp = temp->next;
		i++;
	}
	printf("\n");
} */