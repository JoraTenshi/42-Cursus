/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <<jcallejo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:17:49 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 09:37:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	size_t			i;
	unsigned char	*saux1;
	unsigned char	*saux2;

	i = 0;
	a = 0;
	saux1 = (unsigned char *)s1;
	saux2 = (unsigned char *)s2;
	while (i < n && a == 0)
	{
		if (saux1[i] != saux2[i])
			a = saux1[i] - saux2[i];
		i++;
	}
	return (a);
}
