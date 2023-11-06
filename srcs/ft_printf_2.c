/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:06:45 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/06 03:13:57 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	print_unsigned_int(long int n)
{
	if (n < 0)
		n = 4294967295 + n - 1;
	ft_putnbr_fd(n, 1);
	return (num_len(n, 10));
}

int	print_hexa_nbr(va_list args, int caps)
{
	int				*n;
	unsigned long	n2;
	char			*str;
	int				len;

	n = va_arg(args, int *);
	n2 = (unsigned long)n;
	str = ft_itohex(n2, caps, 16);
	if (str == NULL)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
