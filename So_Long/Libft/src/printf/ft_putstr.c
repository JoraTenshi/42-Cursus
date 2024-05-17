/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:54:44 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/10 10:52:51 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf/ft_printf.h"

int	ft_putstr(char *s)
{
	char	*aux;

	if (!s)
		return (ft_putstr("(null)"));
	aux = s;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	return (s - aux);
}

void	ft_phex(long unsigned int n, char *base)
{
	if (n > 15)
		ft_phex(n / 16, base);
	ft_putchar(base[n % 16]);
}
