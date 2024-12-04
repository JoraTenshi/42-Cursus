/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:33:35 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/27 13:28:39 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_flag_skip(char *str, int *flag)
{
	int	i;

	i = 2;
	if (!str)
		return (0);
	if ((str[0] && str[0] == '-') && (str[1] && str[1] == 'n'))
	{
		while (str[i] == 'n')
			i++;
		if (str[i] == '\0')
		{
			*flag = 1;
			return (1);
		}
	}
	return (0);
}

void	ft_echo(char **matrix, int *error)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (ft_flag_skip(matrix[i], &flag) == 1)
		i++;
	while (matrix[i])
	{
		ft_putstr(matrix[i]);
		if (matrix[i + 1])
			ft_putchar(' ');
		i++;
	}
	if (flag == 0)
		ft_putchar('\n');
	*error = 0;
}
