/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:37:11 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/16 15:58:36 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putnbr_fd(-214748364, fd);
		ft_putchar_fd('8', fd);
	}
	else if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd((nb % 10), fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}

/* int	main(void)
{
	int	fd = open("pipo.txt", O_WRONLY);
	ft_putnbr_fd(-2147483648, fd);
	return (0);
} */