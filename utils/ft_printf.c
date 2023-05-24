/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:39:16 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/24 15:41:21 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	n;

	n = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		ft_putchar(*str);
		str++;
		n++;
	}
	return (n);
}

static int	ft_putnbr(long nb)
{
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(nb * -1));
	if (nb > 9)
		return (ft_putnbr(nb / 10) + ft_putchar(nb % 10 + 48));
	else
		return (ft_putchar(nb + 48));
}

static int	printer(char c, va_list params)
{
	if (c == 's')
		return (ft_putstr((char *)va_arg(params, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr((int)va_arg(params, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	params;

	count = 0;
	i = 0;
	va_start(params, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			count += ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			count += printer(format[i + 1], params);
			i += 2;
		}
	}
	va_end(params);
	return (count);
}