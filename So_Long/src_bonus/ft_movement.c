/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:45 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/12 11:04:16 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	ft_moveup(t_data *data)
{
	if ((mlx_is_key_down(data->mlx, MLX_KEY_W)
			|| mlx_is_key_down(data->mlx, MLX_KEY_UP)) && data->y - 1 >= 0
		&& data->time >= 0.15)
	{
		if (data->map[data->y - 1][data->x] != '1')
		{
			data->player->up->instances[0].y -= 64;
			data->player->down->instances[0].y -= 64;
			data->player->left->instances[0].y -= 64;
			data->player->right->instances[0].y -= 64;
			data->y -= 1;
			data->moves += 1;
			ft_moves(data);
			ft_animation(data->player, 'W');
		}
		data->time = 0;
	}
}

static void	ft_movedown(t_data *data)
{
	if ((mlx_is_key_down(data->mlx, MLX_KEY_S)
			|| mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		&& data->y + 1 <= data->size_y && data->time >= 0.15)
	{
		if (data->map[data->y + 1][data->x] != '1')
		{
			data->player->up->instances[0].y += 64;
			data->player->down->instances[0].y += 64;
			data->player->left->instances[0].y += 64;
			data->player->right->instances[0].y += 64;
			data->y += 1;
			data->moves += 1;
			ft_moves(data);
			ft_animation(data->player, 'S');
		}
		data->time = 0;
	}
}

static void	ft_moveleft(t_data *data)
{
	if ((mlx_is_key_down(data->mlx, MLX_KEY_A)
			|| mlx_is_key_down(data->mlx, MLX_KEY_LEFT)) && data->x - 1 >= 0
		&& data->time >= 0.15)
	{
		if (data->map[data->y][data->x - 1] != '1')
		{
			data->player->up->instances[0].x -= 64;
			data->player->down->instances[0].x -= 64;
			data->player->left->instances[0].x -= 64;
			data->player->right->instances[0].x -= 64;
			data->x -= 1;
			data->moves += 1;
			ft_moves(data);
			ft_animation(data->player, 'A');
		}
		data->time = 0;
	}
}

static void	ft_moveright(t_data *data)
{
	if ((mlx_is_key_down(data->mlx, MLX_KEY_D)
			|| mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		&& data->x + 1 <= data->size_x && data->time >= 0.15)
	{
		if (data->map[data->y][data->x + 1] != '1')
		{
			data->player->up->instances[0].x += 64;
			data->player->down->instances[0].x += 64;
			data->player->left->instances[0].x += 64;
			data->player->right->instances[0].x += 64;
			data->x += 1;
			data->moves += 1;
			ft_moves(data);
			ft_animation(data->player, 'D');
		}
		data->time = 0;
	}
}

void	ft_update(void *param)
{
	t_data	*data;

	data = param;
	if (data->time < 1)
		data->time += data->mlx->delta_time;
	if (data->atime < 1)
		data->atime += data->mlx->delta_time;
	ft_moveup(data);
	ft_movedown(data);
	ft_moveleft(data);
	ft_moveright(data);
	if (data->map[data->y][data->x] == 'C')
		ft_check_collectibles(data);
	else if (data->map[data->y][data->x] == 'E')
		ft_check_game_status(data);
	ft_close(data);
}
