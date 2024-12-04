/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:08:04 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 14:31:32 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_custom_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	str = ft_substr((char *) s1, 0, len + 1);
	return (str);
}

static char	*ft_join_and_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (tmp);
}

static int	ft_check_env(t_data *data, char **home, char **pwd)
{
	if (!ft_get_env(data, "HOME") || !ft_get_env(data, "PWD"))
		return (0);
	*home = ft_get_env(data, "HOME")->value;
	*pwd = ft_get_env(data, "PWD")->value;
	if (!ft_get_env(data, "USER"))
		return (0);
	return (1);
}

static char	*get_string(t_data *data)
{
	char	*string;
	char	*aux;
	char	*home;
	char	*pwd;

	if (!ft_check_env(data, &home, &pwd))
		return (ft_strdup("minishell$ "));
	aux = ft_get_env(data, "USER")->value;
	string = ft_strjoin(aux, ":");
	if (!ft_strncmp(home, pwd, ft_strlen(home)))
		aux = ft_join_and_free(string, "~");
	else
	{
		string = ft_join_and_free(string, pwd);
		aux = ft_join_and_free(string, DEFAULT"$ ");
		return (aux);
	}
	if (!ft_strcmp(home, pwd))
		return (ft_join_and_free(aux, DEFAULT"$ "));
	else
	{
		string = ft_join_and_free(aux, pwd + ft_strlen(home));
		return (ft_join_and_free(string, DEFAULT"$ "));
	}
}

int	ft_read_string(t_data *data)
{
	char	*string;
	char	*aux;

	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
	string = get_string(data);
	aux = readline(string);
	while (!aux)
	{
		printf("\n");
		ft_exit(NULL, data);
		return (free(string), free(aux), 0);
	}
	data->input = ft_custom_strtrim(aux, " \t");
	free(aux);
	free(string);
	if (!data->input)
		return (0);
	else if (*(data->input))
		add_history(data->input);
	return (1);
}
