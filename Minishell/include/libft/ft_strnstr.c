/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:39:53 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:30:39 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long int	i;
	unsigned long int	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (i > len)
			return (0);
		j = 0;
		while (needle[j] == haystack[j + i] && (j + i) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "Hola me llamo pipo";
	char s2[] = "";
	int n = 9;

	printf("%s\n", ft_strnstr(s1, s2, n));
	printf("%s", strnstr(s1, s2, n));
	return (0);
} */
