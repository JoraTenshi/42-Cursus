/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:34:42 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:38 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n != '0')
	{
		ft_memset(s, '\0', n);
	}
}

/* #include <stdio.h>

int	main(void)
{
	char	str[30] = "pipo es un buen perro";

	ft_bzero(str, 4);
	printf("%s", str);
	printf("hello world");
	return (0);
} */
