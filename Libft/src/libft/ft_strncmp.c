/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <<jcallejo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:39:24 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/18 09:37:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*saux1;
	unsigned char	*saux2;

	i = 0;
	saux1 = (unsigned char *)s1;
	saux2 = (unsigned char *)s2;
	while ((saux1[i] != '\0' || saux2[i] != '\0') && i < n)
	{
		if (saux1[i] > saux2[i])
			return (1);
		if (saux1[i] < saux2[i])
			return (-1);
		i++;
	}
	return (0);
}
