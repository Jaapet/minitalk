/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:36:11 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/24 21:12:33 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg;

char	*cat_char(char *str, char c)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return (new);
}

void	catch(int sig)
{
	static int	bit;
	static char	i;

	i *= 2;
	i += (sig & 1);
	bit++;
	if (bit == 8)
	{
		if (!i)
		{
			ft_printf("%s\n", g_msg);
			free (g_msg);
			g_msg = malloc(sizeof(char));
			g_msg[0] = '\0';
		}
		else
			g_msg = cat_char(g_msg, i);
		i = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	g_msg = malloc(sizeof(char));
	g_msg[0] = '\0';
	while (1)
	{
		signal(SIGUSR1, catch);
		signal(SIGUSR2, catch);
		sleep(1);
	}
	return (0);
}
