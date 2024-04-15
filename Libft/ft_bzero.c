/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:25:14 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/09 13:27:07 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*aux;
	size_t	i;

	aux = s;
	i = 0;
	while (i < n)
	{
		aux[i] = '\0';
		i++;
	}
}
