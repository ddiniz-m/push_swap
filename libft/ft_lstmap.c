/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:25 by ddiniz-m          #+#    #+#             */
/*   Updated: 2022/11/11 13:17:20 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	head = NULL;
	if (!f || !del)
		return (0);
	while (lst)
	{
		ft_lstadd_back(&head, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	if (head == NULL)
		ft_lstclear(&lst, del);
	return (head);
}
