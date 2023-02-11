/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:26:54 by hben-bou          #+#    #+#             */
/*   Updated: 2023/01/25 14:12:36 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb % 10 + 48);
}

void	handler(int signal)
{
	static int	i;
	static int	sequence[8];
	char		c;

	if (signal == SIGUSR1)
		sequence[i++] = 1;
	else if (signal == SIGUSR2)
		sequence[i++] = 0;
	if (i == 8)
	{
		c = binary_to_decimal(sequence);
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1337)
	{
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		pause();
	}
}
