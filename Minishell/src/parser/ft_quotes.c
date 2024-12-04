/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:55:01 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/08 14:10:38 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	keep_it_up(char *str, int i, char quote)
{
	while (str[i] && quote && str[i] != quote)
		i++;
	return (i);
}

static int	*get_range(char *str)
{
	int		i;
	int		*range;
	char	quote;

	i = 0;
	quote = 0;
	range = ft_calloc(sizeof(int), 2);
	while (range && i < (int) ft_strlen(str))
	{
		if (str[i] && !quote && (str[i] == '"' || str[i] == '\''))
		{
			quote = str[i];
			range[0] = i++;
		}
		else if (quote && (str[i] == '"' || str[i] == '\''))
		{
			range[1] = i;
			return (range);
		}
		if (quote)
			i = keep_it_up(str, i, quote);
		else
			i++;
	}
	return (free(range), NULL);
}

static char	*triquote(char *str, int *range)
{
	char	*start;
	char	*inter;
	char	*end;

	start = ft_substr(str, 0, range[0]);
	inter = ft_substr(str, range[0] + 1, range[1] - range[0] - 1);
	end = ft_substr(str, range[1] + 1, ft_strlen(str) - range[1]);
	free(str);
	str = ft_strjoin(inter, end);
	free(inter);
	free(end);
	end = ft_strjoin(start, str);
	free(start);
	free(str);
	return (end);
}

static char	*copy_str(char *str, int *range)
{
	char	*aux;
	char	*inter;
	int		len;

	len = ft_strlen(str) - 1;
	if (range[0] == 0 && range[1] == len)
	{
		aux = ft_substr(str, 1, range[1] - 1);
		return (free(str), aux);
	}
	else if (range[0] == 0 && range[1] < len)
	{
		aux = ft_substr(str, 1, range[1] - 1);
		inter = ft_substr(str, range[1] + 1, len - range[1]);
	}
	else if (range[1] == len)
	{
		aux = ft_substr(str, 0, range[0]);
		inter = ft_substr(str, range[0] + 1, range[1] - range[0] - 1);
	}
	else
		return (triquote(str, range));
	free(str);
	str = ft_strjoin(aux, inter);
	return (free(aux), free(inter), str);
}

char	**ft_dequote(char **argv)
{
	int		i;
	int		*range;
	int		end;
	char	*str;

	i = 0;
	while (argv[i])
	{
		range = get_range(argv[i]);
		while (range)
		{
			end = range[1];
			str = copy_str(argv[i], range);
			free(range);
			argv[i] = str;
			range = get_range(&argv[i][end - 1]);
			if (range)
			{
				range[0] += (ft_strlen(str) - ft_strlen(&str[end]) - 1);
				range[1] += (ft_strlen(str) - ft_strlen(&str[end]) - 1);
			}
		}
		i++;
	}
	return (argv);
}
