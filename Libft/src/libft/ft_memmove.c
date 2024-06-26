/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:10:20 by jora              #+#    #+#             */
/*   Updated: 2024/05/09 11:47:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*saux;
	char	*daux;

	i = 0;
	saux = (char *)src;
	daux = dest;
	if (src == NULL && dest == NULL && n > 0)
		return (dest);
	if (src < dest)
	{
		while (n-- > 0)
			daux[n] = saux[n];
	}
	else
	{
		while (i < n)
		{
			daux[i] = saux[i];
			i++;
		}
	}
	return (daux);
}
