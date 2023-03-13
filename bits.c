/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:41:03 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/13 20:00:47 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_to_binary(int num)
{
	int	i;
	static int	binary[32];

	i = 0;
	while (num != 0)
	{
		if (num % 2 == 0)
			binary[i] = 0;
		else
			binary[i] = 1;
		i++;
		num = num / 2;
	}
	return (binary);
}

int	binary_size(int num)
{
	while*
	return (i);
}

int	array_to_int(int *arr, int size)
{
	int	i;
	int	j;
	int	buf;
	
	buf = 0;
	j = size;
	i = 0;
	while (i < j)
	{	
		buf = (10 * buf) + arr[i];
		i++;
	}
	return(buf);
}