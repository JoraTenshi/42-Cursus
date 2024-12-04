/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:49:29 by aarenas-          #+#    #+#             */
/*   Updated: 2024/06/17 17:42:34 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	ft_word_counter(char const *s, char c)
{
	char	bool;
	int		i;
	int		count;

	bool = 'T';
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (bool == 'T' && s[i] != c)
		{
			count++;
			bool = 'F';
		}
		else if (s[i] == c)
			bool = 'T';
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	word_count = 0;
	str = malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (!str)
		return (NULL);
	while (word_count < ft_word_counter(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		str[word_count] = ft_substr(s, j, i - j);
		if (!str[word_count])
			return (ft_free(str), NULL);
		word_count++;
	}
	str[word_count] = NULL;
	return (str);
}

/* void	ft_leaks()
{
	system("leaks -q substr");
	atexit(ft_leaks);
}
 */
/*int	main(void)
{
	int		i = 0;
	char	**str = ft_split("doesntexist", ' ');

	if (!str)
		return (1);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	ft_free(str);
	return (0);
}*/
