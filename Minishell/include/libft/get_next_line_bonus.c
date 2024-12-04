/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:28:47 by aarenas-          #+#    #+#             */
/*   Updated: 2024/05/09 10:26:58 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *next_line, char *c)
{
	char	*aux;

	aux = ft_strjoin(next_line, c);
	free(next_line);
	return (aux);
}

static char	*ft_next_line(char *next_line)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (next_line[i] != '\0' && next_line[i] != '\n')
		i++;
	if (next_line[i] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	aux = ft_calloc((ft_strlen(next_line) - i) + 1, sizeof(char));
	i++;
	while (next_line[i] != '\0')
		aux[j++] = next_line[i++];
	free(next_line);
	if (aux[0] == '\0')
	{
		free(aux);
		return (NULL);
	}
	return (aux);
}

static char	*ft_actual_line(char *next_line)
{
	int		i;
	char	*str;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != '\0')
		i++;
	str = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (next_line[i] != '\n' && next_line[i] != '\0')
	{
		str[i] = next_line[i];
		i++;
	}
	if (next_line[i] != '\0' && next_line[i] == '\n')
		str[i] = '\n';
	return (str);
}

static char	*ft_read_line(int fd, char *next_line)
{
	int		i;
	char	*c;

	i = 1;
	if (!next_line)
		next_line = ft_calloc(sizeof(char), 1);
	c = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (i > 0)
	{
		i = read(fd, c, BUFFER_SIZE);
		if (i < 0)
		{
			free(c);
			return (NULL);
		}
		c[i] = '\0';
		next_line = ft_join(next_line, c);
		if (ft_is_in_str(c, '\n') == 1)
			break ;
	}
	free(c);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[10240];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (next_line[fd] != NULL)
		{
			free(next_line[fd]);
			next_line[fd] = NULL;
		}
		return (NULL);
	}
	next_line[fd] = ft_read_line(fd, next_line[fd]);
	str = ft_actual_line(next_line[fd]);
	next_line[fd] = ft_next_line(next_line[fd]);
	if (str[0] == '\0')
		return (free(str), NULL);
	return (str);
}

/*  void	leaks(void)
{
	system("leaks -q bonus");
} */

/*  int main(void)
{
	char	*str;

	int fd1 = open("pipo.txt", O_RDONLY);
	if (fd1 == -1)
		return 0;
	for(int i = 0; i < 1; i++)
	{
		str = get_next_line(fd1);
		printf("%s", str);
		free(str);
	}
	int fd2 = open("pipo2.txt", O_RDONLY);
	if (fd2 == -1)
		return 0;
	for(int i = 0; i < 1; i++)
	{
		str = get_next_line(fd2);
		printf("%s", str);
		free(str);
	}
	for(int i = 0; i < 1; i++)
	{
		str = get_next_line(fd1);
		printf("%s", str);
		free(str);
	}
	for(int i = 0; i < 1; i++)
	{
		str = get_next_line(fd2);
		printf("%s", str);
		free(str);
	}
	//atexit(leaks);
	return (0);
}  */

/* read devuelve el numero de caracteres que ha leido y los guarda en *c. */