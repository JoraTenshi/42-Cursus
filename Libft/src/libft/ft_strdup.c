/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <<jcallejo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:54:35 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 09:37:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	aux = (char *) malloc(len + 1);
	if (!aux)
		return (NULL);
	while (s[i])
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
