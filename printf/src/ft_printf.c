/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:53:33 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 10:37:21 by jcallejo         ###   ########.fr       */
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
	else if (format == 'p')
	else if (format == 'd')
	else if (format == 'i')
	else if (format == 'u')
	else if (format == 'x')
	else if (format == 'X')
	else if (format == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	node;

	va_start(node, )
}
