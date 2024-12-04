/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:01:59 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/28 10:50:02 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(t_data *data)
{
	char	*path;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!tmp)
	{
		data->error = 1;
		perror("Error");
	}
	path = ft_strjoin(tmp, "\n");
	ft_putstr(path);
	data->error = 0;
	free(tmp);
	free(path);
}
