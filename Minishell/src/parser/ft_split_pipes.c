/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:39:43 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 11:08:32 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	pipecheck(char *str, int *i)
{
	int	j;

	j = *i;
	j++;
	while (str[j] && str[j] == ' ')
	{
		if (str[j] == ' ' && str[j + 1] == '|')
			return (0);
		j += 1;
	}
	return (1);
}

static int	count_args(char *str)
{
	int		i;
	int		args;
	char	quote;

	i = 0;
	args = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i++];
		while (str[i] && quote && str[i] != quote && str[i + 1])
			i++;
		if (quote == str[i])
			quote = 0;
		if (str[i] == '|' && str[i + 1])
			args++;
		if ((str[i] == '|' && str[i + 1] == '|') || (str[i] == '|'
				&& !str[i + 1]) || (str[i] == '|' && !pipecheck(str, &i)))
			return (0);
		if (str[i])
			i++;
	}
	return (args + 1);
}

static int	get_next_cut(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i++];
		while (str[i] && quote && str[i] != quote && str[i + 1])
			i++;
		if (quote == str[i])
			quote = 0;
		if (str[i] == '|')
			return (i);
		if (str[i])
			i++;
	}
	return (i);
}

char	**ft_pipesplit(char *str)
{
	char	**result;
	int		i;
	int		args;

	args = count_args(str);
	if (!args)
		return (NULL);
	result = malloc(sizeof(char *) * (args + 1));
	if (!result)
		return (NULL);
	result[args] = 0;
	i = 0;
	while (*str)
	{
		result[i] = ft_substr(str, 0, get_next_cut(str));
		if (!str[get_next_cut(str)])
			break ;
		str = &str[get_next_cut(str) + 1];
		i++;
	}
	return (result);
}
