/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <<jcallejo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:47:52 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 09:37:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	aux = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux)
		return (NULL);
	j = 0;
	while (s1[j])
		aux[i++] = s1[j++];
	j = 0;
	while (s2[j])
		aux[i++] = s2[j++];
	aux[i] = 0;
	return (aux);
}
