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


char	*ft_itohex(unsigned long long n, int caps)
{
	int		len;
	char	*str;

	len = 16;
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = "0123456789abcdef"[n % 16];
		n /= 16 ;
		len--;
	}
	if (caps == 1)
	{
		len = 0;
		while (str[len])
		{
			str[len] = ft_toupper(str[len]);
			len++;
		}
		
	}
	return (str);
}
