/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:06:45 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/06 03:14:05 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	printf_putstr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_hexa(va_list args)
{
	int		*n;
	char	*str;
	int		len;

	n = va_arg(args, int *);
	str = ft_itobase((unsigned long) n, 0, 16);
	if (str == NULL || n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		free (str);
		return (5);
	}
	len = ft_strlen(str) + 2;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	switch_printf(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (printf_putstr(args));
	else if (c == 'p')
		return (print_hexa(args));
	else if (c == 'd')
		return (print_int(va_arg(args, int)));
	else if (c == 'i')
		return (print_int(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hexa_nbr(args, 0));
	else if (c == 'X')
		return (print_hexa_nbr(args, 1));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			returned;

	returned = 0;
	i = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			returned += switch_printf(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			returned++;
		}
		i++;
	}
	va_end (args);
	return (returned);
}
