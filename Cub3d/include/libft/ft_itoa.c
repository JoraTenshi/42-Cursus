/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:04:19 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/16 12:32:56 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_counter(long int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		count++;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			nbr_count;
	char		*str;
	long int	n_copy;

	n_copy = n;
	nbr_count = ft_nbr_counter(n_copy);
	if (n_copy < 0)
		n_copy *= -1;
	str = malloc(sizeof(char) * (nbr_count) + 1);
	if (!str)
		return (NULL);
	str[nbr_count--] = '\0';
	while (nbr_count >= 0)
	{
		str[nbr_count--] = (n_copy % 10) + '0';
		n_copy /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/* #include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_nbr_counter(0));
	printf("%s", ft_itoa(' '));
	return (0);
} */
