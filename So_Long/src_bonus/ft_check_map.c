/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:05:05 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/25 11:12:16 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_flood_fill(int x, int y, t_data *data, int *exit)
{
	char	c;

	c = data->map[y][x];
	if (c != '1' && c != '*')
	{
		if (c == 'E')
			*exit = 1;
		if (c == 'C')
			data->p_collectibles++;
		data->map[y][x] = '*';
		if (x + 1 < data->size_x)
			ft_flood_fill(x + 1, y, data, exit);
		if (y + 1 < data->size_y)
			ft_flood_fill(x, y + 1, data, exit);
		if (x - 1 >= 0)
			ft_flood_fill(x - 1, y, data, exit);
		if (y - 1 >= 0)
			ft_flood_fill(x, y - 1, data, exit);
	}
}

int	ft_check_rectangle(char **str)
{
	int	plen;
	int	len;
	int	i;

	i = 0;
	plen = ft_strlen(str[0]);
	if (str[i][plen - 1] == '\n')
		plen--;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (str[i][len - 1] == '\n')
			len--;
		if (plen != len)
			return (0);
		i++;
		plen = len;
	}
	return (1);
}

int	ft_check_walls(char **str, int size_x, int size_y)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (j < size_x)
		if (str[i][j++] != '1')
			return (0);
	j = 0;
	while (i < size_y)
		if (str[i++][j] != '1')
			return (0);
	i = size_y - 1;
	j = 0;
	while (j < size_x)
		if (str[i][j++] != '1')
			return (0);
	i = 0;
	j = size_x - 1;
	while (i < size_y)
		if (str[i++][j] != '1')
			return (0);
	return (1);
}

int	ft_check_content(char **str, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_valid_map(t_data data)
{
	int	exit;

	exit = 0;
	if (data.size_y >= 3 && data.size_x >= 4
		&& ft_check_rectangle(data.map) == 1
		&& ft_check_walls(data.map, data.size_x, data.size_y) == 1
		&& ft_check_content(data.map, 'P') == 1
		&& ft_check_content(data.map, 'E') == 1
		&& ft_check_content(data.map, 'C') > 0)
	{
		ft_flood_fill(data.x, data.y, &data, &exit);
		if (exit && data.p_collectibles == data.t_collectibles)
			return (1);
	}
	ft_printf("Error\n");
	return (0);
}
