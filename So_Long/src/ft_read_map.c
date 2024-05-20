/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:25:06 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/20 10:29:44 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_size(char *map)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd) != 0)
		i++;
	return (i);
}

void	ft_read_map(char *map, t_data *data)
{
	char	**map;
	char	*row;
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	i = ft_map_size(map);
	map = malloc((i + 1) * sizeof(char **));
	if (!map)
		return ;
	row = get_next_line(fd);
	data->size_x = ft_strlen(row) - 1;
	i = 0;
	while (row)
	{
		map[i] = ft_strdup(row);
		i++;
		free(row);
		row = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	free(row);
	data->size_y = i;
	data->map = map;
}

void	ft_start_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	data->x = 0;
	data->y = 0;
}

void	ft_get_collectibles(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				data->t_collectibles++;
			x++;
		}
		y++;
	}
}
