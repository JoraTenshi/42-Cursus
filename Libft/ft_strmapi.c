/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:23:09 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/15 12:28:34 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*aux;

	if (!s || !f)
		return (NULL);
	i = 0;
	aux = malloc(ft_strlen(s) + 1);
	if (!aux)
		return (NULL);
	while (s[i])
	{
		aux[i] = f(i, s[i]);
		i++;
	}
	aux[i] = 0;
	return (aux);
}