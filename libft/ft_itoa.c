/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:45:46 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/17 16:19:15 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	int_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

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

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		m;
	char	*str;

	i = int_len(n);
	j = i - 1;
	m = n;
	str = malloc((sizeof(char) * i) + 1);
	if (!str)
		return (0);
	if (n == -2147483648)
		str[j--] = '8';
	n = check_nbr(n);
	str[i] = '\0';
	while ((n < 0 && j > 0) || j >= 0)
	{
		str[j] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	if (m < 0)
		str[0] = 45;
	return (str);
}

/* #include <stdio.h>

int	main()
{
	int	i;

	i = -2147483649;
	printf("%s\n", ft_itoa(i));
} */