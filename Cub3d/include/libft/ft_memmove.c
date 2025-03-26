/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:04:52 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:18 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;
	char		*aux;

	if (!dst && !src)
		return (0);
	tmp = (char *)dst;
	aux = (char *)src;
	if (src < dst)
	{
		while (n-- > 0)
		{
			tmp[n] = aux[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			tmp[i] = aux[i];
			i++;
		}
	}
	return (dst);
}
/* 
#include<stdio.h>  

int	main(void)
{
	char dst[] = "Pipo es un buen perro";
	char src[] = "Perro";

	ft_memmove(dst, src, 5);
	printf("%s", dst);
	return (0);
} */