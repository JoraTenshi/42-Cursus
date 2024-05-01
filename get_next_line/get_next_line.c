/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:40:15 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/01 09:32:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*f_read(int fd, char *buff)
{
	int		byte;
	char	*aux;

	byte = 1;
	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
	{
		free (buff);
		return (NULL);
	}
	while (!ft_strchr(aux, '\n') && byte != 0)
	{
		byte = read(fd, aux, BUFFER_SIZE);
		if (byte == -1)
		{
			free(aux);
			return (NULL);
		}
		aux[byte] = '\0';
		buff = ft_strjoin(buff, aux);
	}
	free(aux);
	return (buff);
}

static char	*cut_buff(char *buff)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	aux = malloc(ft_strlen(buff) - i + 1);
	if (!aux)
		return (NULL);
	i++;
	while (buff[i])
		aux[j] = buff[i++];
	aux[j] = 0;
	free(buff);
	return (aux);
}

static char	*get_line(char *str)
{
	char	*line;
	char	*aux;
	int		i;

	aux = ft_strchr(str, '\n');
	i = (aux - str) + 1;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((*buff && !ft_strchr(buff, '\n')) || !buff)
		buff = f_read(fd, buff);
	if (!buff)
		return (NULL);
	line = get_line(buff);
	buff = cut_buff(buff);
	return (line);
}
