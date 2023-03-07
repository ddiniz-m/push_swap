/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:25 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/07 15:20:04 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*head;

	head = NULL;
	if (!f || !del)
		return (0);
	while (lst)
	{
		ft_lstadd_back(&head, ft_lstnew(f(lst->data)));
		lst = lst->next;
	}
	if (head == NULL)
		ft_lstclear(&lst, del);
	return (head);
}
