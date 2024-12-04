/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:09:09 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:30:57 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long int	srclen;
	unsigned long int	dstlen;
	unsigned long int	size;
	unsigned long int	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	size = dstsize;
	i = 0;
	if (dstsize <= dstlen)
		srclen += dstsize;
	else
		srclen += dstlen;
	while (src[i] != '\0' && dstlen + i + 1 < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen);
}

/* size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize <= dstlen)
		srclen += dstsize;
	else
		srclen += dstlen;
	while (src[i] != '\0' && dstlen + i + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen);
} */

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
    char dest[20] = "hola";
    char src[] = "hola";
	char dest2[20] = "hola";
	char src2[] = "hola";
    size_t size = 8;

    printf("Before ft_strlcat: dest = \"%s\"\n", dest);
    printf("Result of ft_strlcat: %zu\n", ft_strlcat(dest, src, size));
    printf("After ft_strlcat: dest = \"%s\"\n", dest);
	printf("Before strlcat: dest = \"%s\"\n", dest2);
   	printf("%lu\n", strlcat(dest2, src2, size));
    printf("After strlcat: dest = \"%s\"\n", dest2);

    return (0);
} */