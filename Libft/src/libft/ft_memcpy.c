/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:34:10 by jora              #+#    #+#             */
/*   Updated: 2024/05/09 11:47:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*saux;
	char	*daux;

	i = 0;
	daux = dest;
	saux = (char *)src;
	if (src == NULL && dest == NULL && n > 0)
		return (dest);
	while (i < n)
	{
		daux[i] = saux[i];
		i++;
	}
	return (daux);
}
