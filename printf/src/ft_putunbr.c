/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:10:11 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 11:50:37 by jcallejo         ###   ########.fr       */
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
		ft_putchar(rest + '0');
	}
}

int	ft_putunbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	ft_print(nb);
}
