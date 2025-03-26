/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:53:19 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:16 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*ptr, int x, size_t n)
{
	size_t				i;
	unsigned char		*tmp;

	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)x;
		i++;
	}
	return (ptr);
}

/* #include <stdio.h>
int	main(void)
{
	char str[50] = "pipo es un buen perro";
	printf("%s\n", str);
	ft_memset(str, '.', 8);
	printf("%s", str);
	return (0);
} */