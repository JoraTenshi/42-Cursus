/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <<jcallejo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:34:28 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 09:37:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	nlen = ft_strlen(needle);
	i = nlen;
	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	while (*haystack && i <= len)
	{
		if (!(ft_strncmp(haystack, needle, nlen)))
			return ((char *) haystack);
		haystack++;
		i++;
	}
	return (0);
}
