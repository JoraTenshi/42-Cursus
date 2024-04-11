/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:34:28 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/11 14:08:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	if (haystack[0] == '\0')
		return (0);
	while (i <= len && len > 0)
	{
		j = 0;
		a = i;
		while (haystack[i + j] == needle[j] && a < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			a++;
		}
		i++;
	}
	return (0);
}
