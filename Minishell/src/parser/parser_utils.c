/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:35 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 14:06:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	ft_env_name_len(char *name)
{
	size_t	len;

	len = 0;
	while (ft_isalnum(name[len]) || name[len] == '_')
		len++;
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*aux;
	unsigned char	*tmp;

	aux = (unsigned char *)s1;
	tmp = (unsigned char *)s2;
	i = 0;
	while ((aux[i] != '\0' && tmp[i] != '\0')
		&& aux[i] == tmp[i])
		i++;
	return (aux[i] - tmp[i]);
}

char	ft_check_quote(char c, char quote)
{
	if (c == '\'' && !quote)
		return ('\'');
	else if (c == '"' && !quote)
		return ('"');
	else if (c == quote)
		return (0);
	else
		return (quote);
}

char	*ft_minitrim(t_data *data, char	*str)
{
	char	*tmp;

	tmp = ft_strtrim(str, " ");
	data->atmp = tmp;
	return (tmp);
}

int	ft_parser_check_redirs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' && str[i + 1] == '>')
		{
			i++;
			if (str[i + 1] == '>' || str[i + 1] == '<')
				return (0);
		}
		else if (str[i] == '<' && str[i + 1] == '<')
		{
			i++;
			if (str[i + 1] == '<' || str[i + 1] == '>')
				return (0);
		}
		else if ((str[i] == '>' && str[i + 1] == '<')
			|| (str[i] == '<' && str[i + 1] == '>'))
			return (0);
		else
			i++;
	}
	return (1);
}
