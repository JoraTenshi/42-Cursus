/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:31:33 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:30:37 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	aux;
	int				i;
	char			*tmp;

	aux = c;
	i = ft_strlen(s);
	tmp = (char *)s;
	while (i >= 0)
	{
		if (tmp[i] == aux)
		{
			return (&tmp[i]);
		}
		i--;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	char	str[] = "jipo es un uen perro";
	int		c = '\0';

	printf("%s", ft_strrchr(str, c));
	if (ft_strrchr(str, c) == NULL)
		printf("No esta");
	//printf("%zu", ft_strlen(str));
} */