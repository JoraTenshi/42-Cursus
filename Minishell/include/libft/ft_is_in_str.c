/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:15:51 by aarenas-          #+#    #+#             */
/*   Updated: 2024/05/09 10:28:44 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_str(const char *s, int c)
{
	unsigned char	aux;
	size_t			i;
	char			*tmp;

	i = 0;
	aux = (char)c;
	tmp = (char *)s;
	if (tmp == NULL)
		return (0);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == aux)
			return (1);
		i++;
	}
	return (0);
}
