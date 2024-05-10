/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:53:51 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/10 09:25:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf/ft_printf.h"

static void	p_print(long unsigned int n, char *base)
{
	if (n > 15)
		p_print(n / 16, base);
	ft_putchar(base[n % 16]);
}

int	ft_putptr(__UINTPTR_TYPE__ n)
{
	ft_putstr("0x");
	if (n == 0)
	{
		ft_putchar('0');
		return (3);
	}
	p_print(n, "0123456789abcdef");
	return (ft_hlen(n) + 2);
}
