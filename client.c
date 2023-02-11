/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:37:23 by hben-bou          #+#    #+#             */
/*   Updated: 2023/02/11 20:09:14 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(110);
	}
	free(sequence);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		*sequence;
	int		i;

	if (ac != 3)
	{
		write(1, "you gave more or less arguments, try again", 42);
		exit(EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid == 1)
	{
		write(1, "invalid pid", 11);
		exit(EXIT_FAILURE);
	}
	while (av[2][i])
	{
		sequence = decimal_to_binary(av[2][i++]);
		sender(sequence, pid);
	}
	return (0);
}
