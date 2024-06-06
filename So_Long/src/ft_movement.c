/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:45 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/06 13:20:53 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_moveup(t_data *data)
{
	if ((mlx_is_key_down(data->mlx, MLX_KEY_W)
			|| mlx_is_key_down(data->mlx, MLX_KEY_UP)) && data->y - 1 >= 0
		&& data->time >= 0.15)
	{
		if (data->map[data->y - 1][data->x] != '1')
		{
			data->player->instances[0].y -= 64;
			data->y -= 1;
			data->moves += 1;
			ft_printf("Moves: %d\n", data->moves);
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
			data->player->instances[0].y += 64;
			data->y += 1;
			data->moves += 1;
			ft_printf("Moves: %d\n", data->moves);
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
			data->player->instances[0].x -= 64;
			data->x -= 1;
			data->moves += 1;
			ft_printf("Moves: %d\n", data->moves);
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
			data->player->instances[0].x += 64;
			data->x += 1;
			data->moves += 1;
			ft_printf("Moves: %d\n", data->moves);
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
	ft_moveup(data);
	ft_movedown(data);
	ft_moveleft(data);
	ft_moveright(data);
	if (data->map[data->y][data->x] == 'C')
		ft_check_collectibles(data);
	else if (data->map[data->y][data->x] == 'E'
			&& !mlx_is_key_down(data->mlx, MLX_KEY_W)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_A)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_S)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_D)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_UP)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
			&& !mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_check_game_status(data);
	ft_close(data);
}
