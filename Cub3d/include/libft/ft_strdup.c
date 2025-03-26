/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:32:25 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/18 10:43:21 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*aux;

	aux = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (aux == NULL)
		return (0);
	aux = (char *)ft_memcpy(aux, s1, ft_strlen(s1) + 1);
	return (aux);
}
/* #include <stdio.h>

int	main(void)
{
	char	s1[] = "lorem ipsum dolor sit amet";
	printf("%s", ft_strdup(s1));
	return (0);
} */
