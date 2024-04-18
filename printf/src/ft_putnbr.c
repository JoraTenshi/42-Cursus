/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:06:20 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 11:11:56 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_print(int nb)
{
	int	rest;

	if (nb != 0)
	{
		ft_print(nb / 10);
		rest = nb % 10;
		if (rest < 0)
			rest = -rest;
		ft_putchar(rest + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	else if (nb == 0)
		ft_putchar('0');
	ft_print(nb);
}
