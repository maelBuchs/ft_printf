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

int	num_len(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	num_len_hex(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itobase(unsigned long n, int caps, int base)
{
	int		len;
	char	*str;

	len = num_len(n, base);
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = "0123456789abcdef"[n % base];
		if (caps == 1)
			str[len] = ft_toupper(str[len]);
		n /= base ;
		len--;
	}
	return (str);
}

char	*ft_itohex(unsigned int n, int caps, int base)
{
	int		len;
	char	*str;

	len = num_len_hex(n, base);
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = "0123456789abcdef"[n % base];
		if (caps == 1)
			str[len] = ft_toupper(str[len]);
		n /= base ;
		len--;
	}
	return (str);
}
