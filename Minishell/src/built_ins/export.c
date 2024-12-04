/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:31:26 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/28 10:14:08 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

const char	*ft_search(t_env **lst, char *name)
{
	t_env	*node;

	node = *lst;
	while (node)
	{
		if (ft_strncmp(node->name, name, ft_strlen(node->name)) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

static void	ft_free_search(char *name, char *value)
{
	if (name)
		free(name);
	if (value)
		free(value);
}

int	ft_search_replace(t_env **lst, char *str)
{
	t_env	*node;
	char	*name;
	char	*value;
	char	*cut;

	name = NULL;
	cut = ft_strchr(str, '=');
	name = ft_substr(str, 0, (ft_strlen(str) - ft_strlen(cut)));
	value = NULL;
	if (cut)
		value = ft_substr(str, ((ft_strlen(str) - ft_strlen(cut)) + 1),
				ft_strlen(cut) - 1);
	node = *lst;
	while (node)
	{
		if (ft_strncmp(node->name, name, ft_strlen(node->name) + 1) == 0)
		{
			free(node->value);
			node->value = NULL;
			node->value = value;
			return (free(name), 0);
		}
		node = node->next;
	}
	return (ft_free_search(name, value), 1);
}

t_env	*ft_add_to_env(char *str, t_env *lst)
{
	char	*name;
	char	*value;
	char	*cut;

	name = NULL;
	cut = ft_strchr(str, '=');
	name = ft_substr(str, 0, (ft_strlen(str) - ft_strlen(cut)));
	value = NULL;
	if (cut)
		value = ft_substr(str, ((ft_strlen(str) - ft_strlen(cut)) + 1),
				ft_strlen(cut) - 1);
	if (!lst)
		lst = ft_lstnew_tenv(name, value);
	else
	{
		ft_lstadd_back_tenv(&lst, ft_lstnew_tenv(name, value));
	}
	return (lst);
}

void	ft_export(char *str, t_data *data)
{
	t_env	*aux;

	if (str && (ft_isdigit(str[0]) == 1 || (ft_isalpha(str[0]) == 0
				&& str[0] != '_') || ft_str_is_alphanum(&str[1]) == 0))
		return (printf("minishell: export: `%s': not a valid identifier\n",
				str), data->error = 1, (void)0);
	ft_check_and_add(data, str);
	if (!str)
		data->env_export = ft_sort(data->env_export);
	if (!str)
		aux = data->env_export;
	while (!str && aux)
	{
		printf("declare -x %s", aux->name);
		if (aux->value)
			printf("=\"%s\"", aux->value);
		printf("\n");
		aux = aux->next;
	}
	data->error = 0;
	ft_parse_list(data);
}
