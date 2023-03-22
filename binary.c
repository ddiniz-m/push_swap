/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:41:03 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/22 14:16:29 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digits(int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num /= 2;
		i++;
	}
	return (i);
}

//check if number in position i is 0 or 1
int	zero_or_one(int num, int i)
{
	int	j;
	int	buf;

	j = 0;
	buf = num;
	while (j < i)
	{
		buf /= 2;
		j++;
	}
	if (buf % 2 == 0)
		return (0);
	if (buf % 2 == 1)
		return (1);
	return (0);
}
