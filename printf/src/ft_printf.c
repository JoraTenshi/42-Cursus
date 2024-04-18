/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:53:33 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 11:15:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	format_parse(char format, va_list node)
{
	if (format == 'c')
		return (ft_putchar((va_arg(node, int))));
	else if (format == 's')
		return (ft_putstr((va_arg(node, char *))));
	else if (format == 'p')
	else if (format == 'd')
		return (ft_putnbr((va_arg(node, int))));
	else if (format == 'i')
		return (ft_putnbr((va_arg(node, int))));
	else if (format == 'u')
		return (ft_putunbr((va_arg(node, unsigned int))));
	else if (format == 'x')
		return (ft_puthex((va_arg(node, unsigned int), node)));
	else if (format == 'X')
		return (ft_puthex((va_arg(node, unsigned int), node)));
	else if (format == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	node;
}
