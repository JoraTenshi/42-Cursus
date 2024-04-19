/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:16:49 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/19 10:31:04 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static int	ft_hlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

int	ft_puthex(unsigned int n, char format)
{
	char			*base;
	int				i;

	i = ft_hlen(n);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (format == 'x')
		base = "123456789abcdef";
	else if (format == 'X')
		base = "123456789ABCDEF";
	if (n > 15)
	{
		ft_puthex(n / 16, format);
		ft_putchar(base[n % 16]);
	}
	return (i);
}
