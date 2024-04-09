/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jora <jora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:34:10 by jora              #+#    #+#             */
/*   Updated: 2024/04/09 11:48:20 by jora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*saux;
	char	*daux;

	i = 0;
	daux = dest;
	saux = src;
	while (i < n)
	{
		daux[i] = saux[i];
		i++;
	}
	return (daux);
}
