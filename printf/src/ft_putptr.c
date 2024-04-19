/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:53:51 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/19 13:00:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static int	p_print(unsigned int n, char *base)
{
	int	i;

	if (i > 0)
	{
		if (n > 15)
		{
			i += p_print(n / 16, base);
			ft_putchar(base[n % 16]);
		}
	}
	return (i);
}

int	ft_putptr(__UINTPTR_TYPE__ n)
{
	int				i;
	unsigned int	aux;

	i = ft_strlen("0x");
	aux = (unsigned int) n;
	if (n == 0)
	{
		ft_putchar('0');
		return (i + 1);
	}
	i += p_print(n, "123456789abcdef");
	return (i);
}
