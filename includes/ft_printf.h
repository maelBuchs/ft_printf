/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:33:09 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/06 02:58:20 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		switch_printf(char c, va_list args);
void	unsigned_printf(int n);
int		printf_putstr (va_list args);
void	neg_nbr(unsigned int n, int len, char **str);
int	ft_numlen(long long int n);
int	print_hexa(va_list args, int caps);
char	*ft_itohex(unsigned long long n, int caps);
#endif