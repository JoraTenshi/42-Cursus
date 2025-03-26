/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:44:06 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/22 10:57:37 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*aux;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	aux = malloc(sizeof(char) * (size + 1));
	if (aux == NULL)
		return (0);
	ft_memcpy(aux, s1, ft_strlen(s1) + 1);
	aux[ft_strlen(s1) + 1] = '\0';
	ft_strlcat(aux, s2, size + 1);
	return (aux);
} */

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t		size;
	char		*aux;
	int			i;
	int			j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (size == 0)
		return (ft_strdup(""));
	aux = malloc(sizeof(char) * (size + 1));
	if (aux == NULL)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		aux[i + j] = s2[j];
		j++;
	}
	aux[i + j] = '\0';
	return (aux);
}

/* #include <stdio.h>

int	main(void)
{
	char s1[] = "pipo";
	char s2[] = " es un buen perro";
	printf("%s", ft_strjoin(s1, s2));

	return (0);
} */
