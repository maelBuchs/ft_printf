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

void unsigned_printf(int n)
{
	if (n < 0)
		n = 4294967295 - n;
	ft_putnbr_fd(n, 1);
}

int	printf_putstr (va_list args)
{
	char *str;

	str =  va_arg(args, char*);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}


int	switch_printf(char c, va_list args)
{
	int	returned;

	returned = 0;
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);	//print single char
		returned = 1;
	}
	else if (c == 's')
		returned = printf_putstr(args); //print string
	else if (c == 'p')
		returned = print_hexa(args);	//print void * pointer in hexa
	else if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);	//print base 10 (decimal)
	else if (c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);	//print base 10 (int)
	else if (c == 'u')
		unsigned_printf(va_arg(args, unsigned int));	//print base 10 (unsigned)
	else if (c == 'x')
		ft_putchar_fd('x', 1);	//print base 16 lowercase
	else if (c == 'X')
		ft_putchar_fd('X', 1);	//print base 16 uppercase
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);	//print litteraly just %
		return (1);
	}
	return (returned);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			returned;

	returned = 0;
	i = 0;
	va_start (args, str);
	while(str[i])
	{
		if(str[i] == '%')
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
