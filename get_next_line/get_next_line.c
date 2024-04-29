/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:40:15 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/29 13:15:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

static char	f_read(int fd, char *buff)
{
	int		byte;
	char	*aux;

	byte = 1;
	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	while (!ft_strchr(aux, '\n') && byte != 0)
	{
		byte = read(fd, aux, BUFFER_SIZE);
		if (byte == -1)
			return (ft_free(&buff));
		aux[byte] = '\0';
		buff = ft_strjoin(buff, aux);
	}
	free(aux);
	return (buff);
}

static int	find_line_end(char *str, int i)
{
	char	*ptr;
	int		j;
	int		k;

	ptr[i] = str[i];
	j = ft_strlen(ptr);
	if (ptr[j] == '\n')
		j++;
	k = ft_strlen(str);
	return (k - j);
}

static char	*l_read(char *str)
{
	int		i;
	char	*aux;

	i = 0;
	if (!str)
		return (NULL);
	i = find_line_end(str, i);
	aux = malloc(i + 1);
	if (!aux)
		return (NULL);
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		aux[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !buff)
		return (NULL);
	buff = f_read(fd, buff);
	line = l_read(buff[fd]);
}
