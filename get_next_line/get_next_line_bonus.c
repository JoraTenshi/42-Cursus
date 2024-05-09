/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:15:04 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/09 11:50:59 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*f_read(int fd, char *buff)
{
	int		byte;
	char	*aux;

	byte = 1;
	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	while (!ft_strchr(buff, '\n') && byte != 0)
	{
		byte = read(fd, aux, BUFFER_SIZE);
		if (byte == -1)
		{
			free(aux);
			free(buff);
			return (NULL);
		}
		aux[byte] = 0;
		buff = ft_strjoin(buff, aux);
	}
	free(aux);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = f_read(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_getline(buff[fd]);
	buff[fd] = cut_buff(buff[fd]);
	return (line);
}
