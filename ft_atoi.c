/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:43:45 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/28 17:42:17 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (((str[i] >= 9) && (str[i] <= 13))
		|| (str[i] == 32))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{	
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return (num * sign);
}

/* #include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi("  -12312a"));
} */
/*
37: without this condition it would return 
	(num *sign)' even if it hit a non-digit character
*/