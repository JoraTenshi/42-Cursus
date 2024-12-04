/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:36:26 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/25 14:30:22 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*tmp;
	unsigned long int	i;
	unsigned char		x;

	tmp = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == x)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
/* 
#include <stdio.h>

int	main(void)
{
	char	dst[] = "Pip es un buen perro";

	printf("%s", ft_memchr(dst, 'o', 19));
	return (0);
} */
