/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:07:22 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/27 11:51:19 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	xo_yo_fix(t_player *pj)
{
	if (pj->pdx < 0)
		pj->xo -= 20;
	else
		pj->xo = 20;
	if (pj->pdy < 0)
		pj->yo -= 20;
	else
		pj->yo = 20;
	pj->mpx = pj->x / 16;
	pj->mpx_plus_xo = (pj->x + pj->xo) / 16;
	pj->mpx_minus_xo = (pj->x - pj->xo) / 16;
	pj->mpy = pj->y / 16;
	pj->mpy_plus_yo = (pj->y + pj->yo) / 16;
	pj->mpy_minus_yo = (pj->y - pj->yo) / 16;
}

void	ft_controls_hook(void *param)
{
	t_game_core	*game;

	game = (t_game_core *)param;
	game->data->player->m_speed = game->data->mlx->delta_time * 10.0;
	xo_yo_fix(game->pj);
	if (mlx_is_key_down(game->data->mlx, MLX_KEY_ESCAPE))
		ft_exit(game->data, EXIT_SUCCESS);
	if (mlx_is_key_down(game->data->mlx, MLX_KEY_W))
		move_up(game);
	if (mlx_is_key_down(game->data->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->data->mlx, MLX_KEY_S))
		move_down(game);
	if (mlx_is_key_down(game->data->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->data->mlx, MLX_KEY_LEFT))
		turn_left(game);
	if (mlx_is_key_down(game->data->mlx, MLX_KEY_RIGHT))
		turn_right(game);
}
