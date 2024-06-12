/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:50:47 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/12 11:54:37 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_render_slime(t_data *data, int i)
{
	ft_start_pos(data);
	if (!data->textures->slimeup || !data->textures->slimedown
		|| !data->textures->slimeleft || !data->textures->slimeright)
		return (EXIT_FAILURE);
	data->slime[i]->up = mlx_texture_to_image(data->mlx,
			data->textures->slimeup);
	data->slime[i]->down = mlx_texture_to_image(data->mlx,
			data->textures->slimedown);
	data->slime[i]->left = mlx_texture_to_image(data->mlx,
			data->textures->slimeleft);
	data->slime[i]->right = mlx_texture_to_image(data->mlx,
			data->textures->slimeright);
	if (!data->slime)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->slime,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	data->slime[i]->up->instances[0].enabled = 0;
	data->slime[i]->down->instances[0].enabled = 1;
	data->slime[i]->left->instances[0].enabled = 0;
	data->slime[i]->right->instances[0].enabled = 0;
	return (0);
}

void	ft_slime_to_screen(t_data *data, int x, int y)
{
	if (mlx_image_to_window(data->mlx,
			data->slime[data->r_slimes]->up, x, y) < 0)
		return ;
	if (mlx_image_to_window(data->mlx,
			data->slime[data->r_slimes]->down, x, y) < 0)
		return ;
	if (mlx_image_to_window(data->mlx,
			data->slime[data->r_slimes]->left, x, y) < 0)
		return ;
	if (mlx_image_to_window(data->mlx,
			data->slime[data->r_slimes]->right, x, y) < 0)
		return ;
}

void	ft_add_slime(t_data *data, int x, int y)
{
	data->slime[data->r_slimes]->up = mlx_texture_to_image(data->mlx,
			data->textures->slimeup);
	if (!data->slime[data->r_slimes]->up)
		return ;
	data->slime[data->r_slimes]->down = mlx_texture_to_image(data->mlx,
			data->textures->slimedown);
	if (!data->slime[data->r_slimes]->down)
		return ;
	data->slime[data->r_slimes]->left = mlx_texture_to_image(data->mlx,
			data->textures->slimeleft);
	if (!data->slime[data->r_slimes]->left)
		return ;
	data->slime[data->r_slimes]->right = mlx_texture_to_image(data->mlx,
			data->textures->slimeright);
	if (!data->slime[data->r_slimes]->right)
		return ;
	ft_slime_to_screen(data, x, y);
}

void	ft_slime_list(t_data *data, int x, int y)
{
	if (data->r_slimes == 0)
	{
		data->t_slimes = ft_check_content('M', data->map);
		data->slime = malloc((sizeof(mlx_image_t) * data->t_slimes) + 1);
		if (!data->slime)
			return ;
		data->slime[0] = image;
		ft_add_slime(data, image->instances[0].x, image->instances[0].y);
		data->slime[data->t_slimes] = 0;
		data->r_slimes++;
	}
	else
	{
		ft_add_slime(data, image->instances[0].x, image->instances[0].y);
		data->r_slimes++;
	}
}

void	ft_slime_movement(t_data *data)
{
	
}
