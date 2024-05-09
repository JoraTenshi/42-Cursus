/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:53:33 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/22 10:53:21 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	format_parse(char format, va_list node)
{
	if (format == 'c')
		return (ft_putchar(va_arg(node, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(node, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(node, __UINTPTR_TYPE__)));
	else if (format == 'd')
		return (ft_putnbr(va_arg(node, int)));
	else if (format == 'i')
		return (ft_putnbr(va_arg(node, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(node, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(node, unsigned int), format));
	else if (format == 'X')
		return (ft_puthex(va_arg(node, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	node;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(node, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += format_parse(str[++i], node);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(node);
	return (len);
}
