/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:09 by hben-bou          #+#    #+#             */
/*   Updated: 2023/01/25 15:06:35 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		ft_putchar(nb + 48);
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static int		i;
	static int		sequence[8];
	char			c;
	static pid_t	spid;

	(void)context;
	if (spid != info->si_pid)
	{
		i = 0;
		spid = info->si_pid;
	}
	if (signal == SIGUSR1)
		sequence[i++] = 1;
	else if (signal == SIGUSR2)
		sequence[i++] = 0;
	if (i == 8)
	{
		c = binary_to_decimal(sequence);
		if (c == '\0')
			kill(spid, SIGUSR1);
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	act.sa_sigaction = handler;
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1337)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
