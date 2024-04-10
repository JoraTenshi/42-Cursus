/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:10:03 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/10 18:28:06 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*aux;

	i = ft_strlen(s) - 1;
	if ((char)c == '\0')
		return ((char *)s);
	else
	{
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				aux = (char *)s;
			i++;
		}
		return (aux);
	}
	return (0);
}
