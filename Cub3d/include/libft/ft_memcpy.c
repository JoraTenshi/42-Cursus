/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:59:43 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:20 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*aux;

	tmp = (char *)dst;
	aux = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		tmp[i] = aux[i];
		i++;
	}
	return (dst);
}

/* #include<stdio.h>  

int	main(void)
{
	char dst[] = "";
	char src[] = "";

	ft_memcpy(dst, src, 5);
	printf("%s", dst);
	return (0);
} */
