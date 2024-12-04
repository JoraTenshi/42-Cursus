/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:51:47 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/19 13:23:21 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char const *s, char c)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;
	int		limit;
	char	*aux;

	i = 0;
	j = ft_strlen(s1);
	count = 0;
	while (isinset(set, s1[i]) && i < j)
		i++;
	while (isinset(set, s1[j]) && j > 0)
		j--;
	limit = (j - i) + 1;
	if (s1[0] == '\0' || j == 0)
		aux = malloc(sizeof(char) * (j + 1));
	else
		aux = malloc(sizeof(char) * (limit + 1));
	if (aux == NULL)
		return (0);
	while ((count < limit) && s1[0] != '\0')
		aux[count++] = s1[i++];
	aux[count] = '\0';
	return (aux);
}
/*Al malloc hay que sumarle dos porque el strlen no cuenta el nulo
y se salta el nulo en isinset

En el isinset, la condicion de j >= 0 es por si el set va a borrar el string
entero. Sin esto, entra en negativo y el malloc no funciona

De normal el malloc se hace con limit para calcular lo que se ha borrado por 
delante y por detrás, sumando 1 para dejar espacio al nulo, pero si se ha
borrado todo, la j + 1 deja espacio para el null

while ((count < limit) && s1[0] != '\0')
el s1[0] != '\0' es porque si el string esta vacio, el limit = 1. Y no
queremos que copie nada más que el nulo*/

/* La Funcion en si lo que hace es elminar lo que tu le digas en set, tanto
por delante como por detrás hasta encontrar otra cosa */

/*#include <stdio.h>

int	main(void)
{
	char s1[] = " Hola pipo        ";
	char s2[] = "podasd"; 
 	printf("%s", ft_strtrim(s1, s2));
	return (0);
} */
