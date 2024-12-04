/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:00:08 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/28 16:57:20 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_strchr_destroy(const char *s, int c)
{
	unsigned char	aux;
	int				i;
	char			*tmp;

	aux = (char)c;
	tmp = (char *)s;
	i = ft_strlen(tmp);
	while (i >= 0)
	{
		if (tmp[i] == aux)
		{
			tmp[i] = '\0';
			return (&tmp[0]);
		}
		i--;
	}
	if (aux == '\0' || c == 1024)
	{
		return (&tmp[0]);
	}
	else
		return (NULL);
}

char	*ft_manage_go_back(t_data *data)
{
	char	*obj_dir;
	char	*new_obj_dir;

	obj_dir = ft_strdup(ft_search(&data->env_export, "PWD"));
	new_obj_dir = ft_strchr_destroy(obj_dir, '/');
	return (new_obj_dir);
}

static void	ft_change_pwd_env(t_env **lst, char *name, char *new_route)
{
	t_env	*aux;
	int		i;

	i = 0;
	aux = *lst;
	while (aux->next)
	{
		if (i == 0 && ft_strncmp(aux->name, name, ft_strlen(aux->name)) == 0)
		{
			if (aux->value)
				free(aux->value);
			aux->value = new_route;
			break ;
		}
		aux = aux->next;
	}
}

static void	ft_manage_pwd_change(t_data *data, char *oldpwd_env, char *old_exp)
{
	char	*pwd_env;
	char	*pwd_export;

	pwd_env = getcwd(NULL, 0);
	pwd_export = getcwd(NULL, 0);
	ft_change_pwd_env(&data->env, "PWD", pwd_env);
	ft_change_pwd_env(&data->env_export, "PWD", pwd_export);
	ft_change_pwd_env(&data->env, "OLDPWD", oldpwd_env);
	ft_change_pwd_env(&data->env_export, "OLDPWD", old_exp);
}

void	ft_cd(t_data *data, char **str)
{
	char	*home;
	char	*oldpwd_export;
	char	*oldpwd_env;

	home = getenv("HOME");
	if (str && str[1])
	{
		data->error = 1;
		return (printf("minishell: cd: too many arguments\n"), (void)0);
	}
	oldpwd_export = getcwd(NULL, 0);
	oldpwd_env = getcwd(NULL, 0);
	if (str && ft_strncmp(str[0], "-", 1) == 0
		&& chdir(ft_search(&data->env, "OLDPWD=")) < 0)
		perror("minishell: cd");
	if (str && ft_how_to_go_back(str[0]) == 1)
		if (ft_aux_cd_if(data) == 1)
			return (free(oldpwd_env), free(oldpwd_export), (void)0);
	if (str && ft_strncmp(str[0], "-", 1) != 0
		&& ft_how_to_go_back(str[0]) == 0 && chdir(str[0]) < 0)
		perror("minishell: cd");
	else if (!str && chdir(home) < 0)
		perror("minishell: cd");
	ft_manage_pwd_change(data, oldpwd_env, oldpwd_export);
	data->error = 0;
}
