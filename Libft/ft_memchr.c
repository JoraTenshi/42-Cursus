/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:46:41 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/11 13:16:31 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*saux;

	i = 0;
	saux = (unsigned char *)s;
	while (i < n)
	{
		if (saux[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
