/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:15:23 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/10 18:17:50 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)s);
	}
	else
	{
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return ((char *)s);
			i++;
		}
	}
	return (0);
}
