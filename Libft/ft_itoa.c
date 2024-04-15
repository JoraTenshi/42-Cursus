/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:01 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/15 12:16:51 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		res;
	char	*aux;

	i = n_len(n);
	if (n < 0 || n == 0)
		i++;
	aux = malloc(i + 1);
	if (!aux)
		return (NULL);
	aux[i] = 0;
	if (n < 0)
		aux[0] = '-';
	else if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		res = n % 10;
		if (res < 0)
			res = -res;
		n /= 10;
		aux[--i] = res + '0';
	}
	return (aux);
}
