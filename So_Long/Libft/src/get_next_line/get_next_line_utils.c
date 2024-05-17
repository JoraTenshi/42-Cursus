/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:45:36 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/10 09:26:57 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line/get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof (char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	aux = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux)
		return (NULL);
	j = 0;
	while (s1[j])
		aux[i++] = s1[j++];
	j = 0;
	while (s2[j])
		aux[i++] = s2[j++];
	aux[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (aux);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_getline(char *buff)
{
	int		i;
	char	*aux;

	i = 0;
	if (!*buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	aux = malloc(i + 2);
	if (!aux)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		aux[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		aux[i] = buff[i];
		i++;
	}
	aux[i] = 0;
	return (aux);
}

char	*cut_buff(char *buff)
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
		aux[j++] = buff[i++];
	aux[j] = 0;
	free(buff);
	return (aux);
}
