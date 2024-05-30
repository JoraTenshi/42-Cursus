/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:54:05 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/30 12:26:09 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_exit_status(t_data *data)
{
	if (data->p_collectibles > 0)
		data->exit_image[0]->enabled = 1;
	else
	{
		data->exit_image[0]->enabled = 0;
		data->exit_image[1]->enabled = 1;
	}
}

void	ft_check_collectibles(t_data *data)
{
	int	i;

	if (data->map[data->y][data->x] == 'C')
	{
		i = 0;
		while (data->collectible_images[i])
		{
			if (data->collectible_images[i]->instances[0].x
				== data->player->instances[0].x
				&& data->collectible_images[i]->instances[0].y
				== data->player->instances[0].y)
			{
				data->collectible_images[i]->enabled = 0;
				data->p_collectibles--;
				data->map[data->y][data->x] = '0';
				ft_exit_status(data);
				return ;
			}
			i++;
		}
	}
}

int	ft_collectible_array(t_data *data, mlx_image_t *image)
{
	if (data->p_collectibles == 0)
	{
		data->collectible_images = malloc(sizeof(mlx_image_t *)
				* (data->t_collectibles + 1));
		if (!data->collectible_images)
			return (EXIT_FAILURE);
		data->collectible_images[0] = image;
		data->p_collectibles = 1;
	}
	else
	{
		data->collectible_images[data->p_collectibles] = image;
		data->p_collectibles++;
	}
	return (0);
}
