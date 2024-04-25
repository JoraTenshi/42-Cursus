/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:40:15 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/25 10:50:33 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*f_read(int fd, char *res)
{
	char	*buff;
	int		count;

	buff = malloc(sizeof(BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		res = ft_strjoin(res, buff);
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
}
