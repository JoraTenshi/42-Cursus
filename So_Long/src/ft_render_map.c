/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:54:01 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/05 12:05:16 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_close_exits(t_data *data)
{
	data->exit_image[0]->enabled = 1;
	data->exit_image[1]->enabled = 0;
}

void	ft_render_exit(int i, int j, t_data *data)
{
	data->exit_image = malloc(sizeof(mlx_image_t *) * 2);
	if (!data->exit_image)
		return ;
	data->exit_image[0] = mlx_texture_to_image(data->mlx,
			data->textures->exit_closed);
	data->exit_image[1] = mlx_texture_to_image(data->mlx,
			data->textures->exit_open);
	if (mlx_image_to_window(data->mlx, data->exit_image[0], j * 64, i * 64) < 0
		|| mlx_image_to_window(data->mlx, data->exit_image[1],
			j * 64, i * 64) < 0)
		return ;
	ft_close_exits(data);
}

int	ft_fill_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_render_sprite(i, j, data, data->textures->floor);
			if (data->map[i][j] == '1')
				ft_render_sprite(i, j, data, data->textures->wall);
			else if (data->map[i][j] == 'C')
				ft_render_sprite(i, j, data, data->textures->collectible);
			else if (data->map[i][j] == 'E')
				ft_render_exit(i, j, data);
			j++;
		}
		i++;
	}
	return (0);
}
