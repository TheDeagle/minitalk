/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:33:47 by hben-bou          #+#    #+#             */
/*   Updated: 2023/01/25 14:04:14 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	ft_power(int nb1, int nb2)
{
	int	res;

	res = 1;
	while (nb2--)
		res *= nb1;
	return (res);
}

char	binary_to_decimal(int *sequence)
{
	int	i;
	int	k;
	int	c;

	i = 0;
	k = 7;
	c = 0;
	while (i < 8)
	{
		c += (sequence[i] * ft_power(2, k));
		i++;
		k--;
	}
	return ((char)c);
}

int	*decimal_to_binary(int c)
{
	int	i;
	int	*sequence;

	sequence = (int *)malloc(sizeof(int) * 8);
	if (!sequence)
	{
		write(1, "An error occured during memory allocation", 41);
		exit(EXIT_FAILURE);
	}
	i = 7;
	while (c)
	{
		sequence[i--] = c % 2;
		c /= 2;
	}
	while (i > -1)
	{
		sequence[i--] = 0;
	}
	return (sequence);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - 48;
	return (res * sign);
}
