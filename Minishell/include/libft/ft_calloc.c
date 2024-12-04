/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:40:23 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:36 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	int				i;
	int				limit;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (0);
	i = 0;
	limit = count * size;
	while (i < limit)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
/* 
#include <unistd.h>

int	main(void)
{
	char *test = ft_calloc(5, sizeof(char));

	int i = 0;
	while (i <= 11)
	{
		if (test[i] == '\0')
			write(1, "A", 1);
		i++;
	}
	return (0);
} */
