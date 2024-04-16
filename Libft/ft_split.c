/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:04:39 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/16 09:15:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (str[a] != c)
		{
			while (str[a] != c && str[a])
				a++;
			count++;
		}
		else
			a++;
	}
	return (count);
}

static char	*word_cpy(char *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char	**failsafe(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	*aux;
	char	**split;

	i = 0;
	aux = (char *)s;
	count = word_count((char *)s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split || !s)
		return (NULL);
	while (i < count && *aux)
	{
		while (*aux == c && *aux)
			aux++;
		split[i] = word_cpy(aux, c);
		if (!split[i])
			return (failsafe(split, i));
		i++;
		while (*aux != c && *aux)
			aux++;
	}
	split[i] = 0;
	return (split);
}
