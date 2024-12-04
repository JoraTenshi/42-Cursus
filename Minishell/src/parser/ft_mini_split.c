/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:16:15 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 14:08:16 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	keep_running(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		*i += 1;
}

static void	count_args_aux(char *str, int *i, char *quote)
{
	*quote = str[*i];
	*i += 1;
	if (str[*i] == *quote)
	{
		*i += 1;
		*quote = 0;
	}
	while (str[*i] && str[*i] != *quote && *quote)
		*i += 1;
	if ((str[*i] == '\'' || str[*i] == '"') && *quote)
		*i += 1;
	*quote = 0;
}

static int	get_next_cut(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			count_args_aux(str, &i, &quote);
		else
		{
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
				i++;
			if (str[i] == '\'' || str[i] == '"')
				count_args_aux(str, &i, &quote);
		}
		if (str[i] == ' ' || !str[i])
		{
			keep_running(str, &i);
			return (i);
		}
	}
	return (i);
}

static int	count_args(char *str)
{
	int		i;
	int		args;
	char	quote;

	i = 0;
	args = 0;
	quote = 0;
	while (str[i] && ft_parser_check_redirs(str))
	{
		if (str[i] == '\'' || str[i] == '"')
			count_args_aux(str, &i, &quote);
		else
		{
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
				i++;
			if (str[i] == '\'' || str[i] == '"')
				count_args_aux(str, &i, &quote);
		}
		if (str[i] == ' ' || !str[i])
		{
			keep_running(str, &i);
			args++;
		}
	}
	return (args);
}

char	**ft_minisplit(t_data *data, char *str)
{
	char	**res;
	char	*aux;
	char	*tmp;
	int		i;
	int		args;

	tmp = ft_minitrim(data, str);
	args = count_args(tmp);
	if (!args)
		return (free(tmp), NULL);
	res = malloc(sizeof(char *) * args + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (*tmp)
	{
		aux = ft_substr(tmp, 0, get_next_cut(tmp));
		res[i++] = ft_custom_strtrim(aux, " ");
		free(aux);
		if (!tmp[get_next_cut(tmp)])
			break ;
		tmp = &tmp[get_next_cut(tmp)];
	}
	res[args] = 0;
	return (free(data->atmp), res);
}
