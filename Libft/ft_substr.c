/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:05:10 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/16 09:15:13 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
	{
		aux = malloc(1);
		if (!aux)
			return (NULL);
		aux[0] = '\0';
		return (aux);
	}
	if (len > (size_t)ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	while (i < len && s[start] != '\0')
		aux[i++] = s[start++];
	aux[i] = '\0';
	return (aux);
}
