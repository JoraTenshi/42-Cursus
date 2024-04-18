/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:28:49 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 19:37:56 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static int	n_len(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int		i;
	unsigned int		res;
	char				*aux;

	i = n_len(n);
	if (n == 0)
		i++;
	aux = malloc(i + 1);
	if (!aux)
		return (NULL);
	aux[i] = 0;
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		res = n % 10;
		n /= 10;
		aux[--i] = res + '0';
	}
	return (aux);
}
