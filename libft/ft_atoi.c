/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:43:45 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/08 13:49:25 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{	
		num = (*str - '0') + (num * 10);
		if (*str < '0' && *str > '9' )
			return (0);
		str++;
	}
	if ((*str + 1 == '\0') && (num * sign == -2147483648))
		return (num * sign);
	if ((num * sign > 2147483647) || (num * sign < -2147483648))
		return (0);
	return (num * sign);
}

/* int	main()
{
	printf("%d\n", ft_atoi("-2147483650"));
} */