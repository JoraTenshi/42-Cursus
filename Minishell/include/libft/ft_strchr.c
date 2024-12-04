/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:02:45 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:11 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	aux;
	int				i;
	char			*tmp;

	aux = (char)c;
	i = 0;
	tmp = (char *)s;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == aux)
			return (&tmp[i]);
		i++;
	}
	if (aux == '\0' || c == 1024)
	{
		return (&tmp[i]);
	}
	else
		return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	char	str[] = "pipo es un buen perro";
	int		c = '\0';

	printf("%s", ft_strchr(str, c));
	if (ft_strchr(str, '\0') == NULL)
		printf("No esta");
} */