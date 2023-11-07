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

int	print_int(long int n)
{
	ft_putnbr_fd(n, 1);
	if (n < 0)
		return (num_len(-n, 10) + 1);
	return (num_len(n, 10));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

unsigned int	print_unsigned_int(long int n)
{
	if (n < 0)
		n = 4294967295 + n - 1;
	ft_putnbr_fd(n, 1);
	return (num_len(n, 10));
}
