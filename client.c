/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:36:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/24 20:43:39 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	long int	val;
	int			i;

	val = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			throw_error("PID has to be positive int, only numbers");
		val = val * 10 + str[i] - '0';
		i++;
	}
	return (val);
}

void	send(int pid, char *msg, int len)
{
	int	i;
	int	shift;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if (msg[i] >> shift & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
			shift--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		throw_error("the program takes 2 args");
	send(ft_atoi(argv[1]), argv[2], ft_strlen(argv[2]));
	return (0);
}
