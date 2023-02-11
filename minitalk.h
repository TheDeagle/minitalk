/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:34:16 by hben-bou          #+#    #+#             */
/*   Updated: 2023/01/25 12:28:52 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		*decimal_to_binary(int c);
int		ft_power(int nb1, int nb2);
char	binary_to_decimal(int *sequence);
int		ft_strlen(char *str);
void	ft_putchar(int c);
void	ft_putnbr(int nb);

#endif
