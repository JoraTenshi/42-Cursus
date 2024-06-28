/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:50:37 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/09 11:47:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

void	*ft_calloc(size_t nmem, size_t size)
{
	void	*ptr;

	ptr = malloc(nmem * size);
	if (ptr)
		ft_bzero(ptr, nmem * size);
	return (ptr);
}
