/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:58:22 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/19 09:59:04 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int	check_base(char *base)
{
	int	a;
	int	b;

	a = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[a] != '\0')
	{
		b = a + 1;
		if (base[a] == '-' || base[a] == '+')
			return (0);
		while (base[b] != '\0')
		{
			if (base[b] == base[a])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				radix;
	unsigned int	nbaux;
	char			digits[1000];

	i = 0;
	nbaux = nbr;
	if (check_base(base) == 0)
		return ;
	radix = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbaux = -nbr;
	}
	while (nbaux > 0)
	{
		digits[i] = base[nbaux % radix];
		nbaux /= radix;
		i++;
	}
	while (i-- > 0)
		write(1, digits + i, 1);
}
