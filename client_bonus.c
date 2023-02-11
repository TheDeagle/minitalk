/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:15:22 by hben-bou          #+#    #+#             */
/*   Updated: 2023/01/25 14:05:03 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	client_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "the message has arrived succesfuly\n", 36);
}

void	sender(int *sequence, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (sequence[i] == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "An error occured\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		else if (sequence[i] == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "An error occured\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		i++;
		usleep(120);
	}
	free(sequence);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;
	int		*sequence;

	if (ac != 3)
	{
		write(1, "You gave more or less arguments, try again", 42);
		exit(EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	while (i <= ft_strlen(av[2]))
	{
		sequence = decimal_to_binary(av[2][i++]);
		usleep(100);
		sender(sequence, pid);
		signal(SIGUSR1, client_handler);
	}
	return (0);
}
