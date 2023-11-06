/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:35:06 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/06 01:58:13 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	*test;
	int	gay;

	test = &gay;
	printf("\nft printf : %d\n", ft_printf(" %p", test));
	printf("\nprintf : %d\n", printf(" %p", test));
	return (0);
}
