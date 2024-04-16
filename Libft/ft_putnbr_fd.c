/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:16:11 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/16 09:15:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_fd(int n, int fd)
{
	int		res;

	if (n != 0)
	{
		ft_print_fd(n / 10, fd);
		res = n % 10;
		if (res < 0)
			res = -res;
		ft_putchar_fd(res + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else if (n == 0)
		ft_putchar_fd('0', fd);
	ft_print_fd(n, fd);
}
