/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:31:52 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 10:04:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*ft_get_env(t_data *data, char *name)
{
	t_env	*current;

	current = data->env;
	if (!current)
		return ((t_env *)0);
	while (current->next)
	{
		if (!ft_strcmp(name, current->name))
			return (current);
		current = current->next;
	}
	if (!ft_strcmp(name, current->name))
		return (current);
	return ((t_env *)0);
}

static char	*multi_join(t_env *env, char *str, int i)
{
	size_t	name_len;
	char	*aux;
	char	*new_str;

	name_len = ft_env_name_len(&str[i + 1]);
	ft_bzero(&str[i], name_len + 1);
	if (env)
		aux = ft_strjoin(str, env->value);
	else
		aux = ft_strjoin(str, "");
	i += name_len + 1;
	new_str = ft_strjoin(aux, &str[i]);
	return (free(aux), new_str);
}

static char	*aux_rep_env(t_data *data, char *str, int i)
{
	char	*tmp;
	char	*qmark;
	char	*aux;

	if (!str)
		return (NULL);
	tmp = 0;
	aux = 0;
	qmark = 0;
	if (str[i + 1] == '?')
	{
		aux = ft_itoa(data->error);
		qmark = ft_strjoin(aux, &str[i + 2]);
		return (free(aux), qmark);
	}
	if (str[i + 1] == ' ' || !str[i + 1])
		return (ft_strdup("$"));
	if (str[i + 1] == '1' && (str[i + 2] == ' ' || !str[i + 2]))
		return (ft_strdup("minishell"));
	aux = ft_substr(&str[i + 1], 0, ft_env_name_len(&str[i + 1]));
	tmp = multi_join(ft_get_env(data, aux), str, i);
	free(aux);
	return (tmp);
}

char	*ft_str_replace_env(t_data *data, char *str)
{
	char	*str_new;
	char	quote;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	str_new = 0;
	quote = 0;
	while (str[++i])
	{
		quote = ft_check_quote(str[i], quote);
		if (str[i] == '$' && quote != '\'')
		{
			str_new = aux_rep_env(data, str, i);
			break ;
		}
	}
	if (!str_new)
		return (str);
	return (free(str), str_new);
}

void	ft_parse_env(t_data *data, char **argv)
{
	int		i;
	int		j;
	char	quotes;

	i = -1;
	quotes = 0;
	while (argv[++i])
	{
		j = -1;
		while (*argv[i] && argv[i][++j])
		{
			if ((argv[i][j] == '"' || argv[i][j] == '\'') && !quotes)
				quotes = argv[i][j];
			else if (argv[i][j] == quotes)
				quotes = 0;
			if (argv[i][j] == '$' && (quotes == '"' || quotes == 0))
				argv[i] = ft_str_replace_env(data, argv[i]);
			if (!argv[i][j])
				break ;
		}
	}
}
