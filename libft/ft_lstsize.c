/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:30 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/10 15:18:28 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_stack **lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
