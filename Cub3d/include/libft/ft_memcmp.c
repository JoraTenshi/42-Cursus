/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:07:46 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:22 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*tmp1;
	unsigned const char	*tmp2;

	tmp1 = (unsigned const char *)s1;
	tmp2 = (unsigned const char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (tmp1[i] == tmp2[i]))
		i++;
	return (tmp1[i] - tmp2[i]);
}

/* #include <stdio.h>

int	main(void)
{
	char	s1[] = "Pipoaaaun buen perro";
	char	s2[] = "Pipoa  es un buen perro";

	printf("%d", ft_memcmp(s1, s2, 0));
} */