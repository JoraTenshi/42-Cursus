/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:34:23 by aarenas-          #+#    #+#             */
/*   Updated: 2024/09/17 13:52:33 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_type_filter(char c, va_list *list, int *p_w)
{
	if (c == 'c')
		ft_printf_putchar(va_arg(*list, int), p_w);
	else if (c == 's')
		ft_printf_putchar(va_arg(*list, char *), p_w);
	else if (c == '%')
		ft_printf_putchar('%', p_w);
	else if (c == 'd' || c == 'i')
		ft_printf_putnbr_dec(va_arg(*list, int), p_w);
	else if (c == 'u')
		ft_printf_putnbr_dec(va_arg(*list, unsigned int), p_w);
	else if (c == 'x')
		ft_printf_putnbr_hexa(va_arg(*list, unsigned int), 'x', p_w);
	else if (c == 'X')
		ft_printf_putnbr_hexa(va_arg(*list, unsigned int), 'X', p_w);
	else if (c == 'p')
	{
		ft_printf_putstr("0x", p_w);
		ft_printf_putnbr_hexa(va_arg(*list, unsigned long long), 'x', p_w);
	}
	else
	{
		ft_printf_putchar('%', p_w);
		ft_printf_putchar(c, p_w);
	}
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		printed_words;
	va_list	list;

	printed_words = 0;
	i = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_type_filter(str[i + 1], &list, &printed_words);
			i++;
		}
		else if (str[i])
			ft_printf_putchar(str[i], &printed_words);
		if (printed_words == -1)
			break ;
		i++;
	}
	va_end(list);
	return (printed_words);
}

/* void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	void *max = 9223372036854775807;
	void *min = -9223372036854775808;
	
	ft_printf(" %p %p ", max, min);
	printf(" %p %p ", max, min);
	atexit(ft_leaks);
	return (0);
} */
