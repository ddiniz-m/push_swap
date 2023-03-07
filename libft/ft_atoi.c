/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:43:45 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/07 18:58:11 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_nbr(int n)
{
	if (n == -2147483648)
	{
		n = (n / 10) * (-1);
		return (n);
	}
	if (n < 0)
		n = n * (-1);
	if (n > 2147483647 || n <= -2147483648)
		return (0);
	return (n);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

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
		if (*str < '0' || *str > '9' )
			return (0);
		num = (*str - '0') + (num * 10);
		str++;
	}
	if (*str + 1 == '\0' && num == -2147483648)
		return (-2147483648);
	if (num > 2147483647 || num <= -2147483647)
		return (0);
	return (num * sign);
}

int	main()
{
	printf("%d\n", ft_atoi("-2147483648"));
}