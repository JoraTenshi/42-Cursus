/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:13:34 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/09 11:47:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		slen;
	char		*aux;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	slen = ft_strlen(s1);
	while (slen > 0 && ft_strchr(set, s1[slen]))
		slen--;
	aux = ft_substr((char *) s1, 0, slen + 1);
	return (aux);
}
