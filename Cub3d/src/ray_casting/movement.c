/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:25:42 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/21 13:06:47 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_up(t_game_core *game)
{
	if (game->data->map[(int)(game->pj->y + game->pj->pdy
			* game->data->player->m_speed) / 16]
		[(int)(game->pj->x) / 16] == '0')
		game->pj->y += game->pj->pdy * game->data->player->m_speed;
	if (game->data->map[(int)(game->pj->y) / 16]
		[(int)(game->pj->x + game->pj->pdx * game->data->player->m_speed)
			/ 16] == '0')
		game->pj->x += game->pj->pdx * game->data->player->m_speed;
}

void	move_down(t_game_core *game)
{
	if (game->data->map[(int)(game->pj->y - game->pj->pdy
			* game->data->player->m_speed) / 16]
		[(int)(game->pj->x) / 16] == '0')
		game->pj->y -= game->pj->pdy * game->data->player->m_speed;
	if (game->data->map[(int)(game->pj->y) / 16]
		[(int)(game->pj->x - game->pj->pdx
			* game->data->player->m_speed) / 16] == '0')
		game->pj->x -= game->pj->pdx * game->data->player->m_speed;
}

void	move_left(t_game_core *game)
{
	if (game->data->map[(int)(game->pj->y - cos(game->pj->pangle)
			* 5 * game->data->player->m_speed) / 16]
		[(int)(game->pj->x) / 16] == '0')
		game->pj->y -= cos(game->pj->pangle) * 5 * game->data->player->m_speed;
	if (game->data->map[(int)(game->pj->y) / 16]
		[(int)(game->pj->x + sin(game->pj->pangle)
			* 5 * game->data->player->m_speed) / 16] == '0')
		game->pj->x += sin(game->pj->pangle) * 5 * game->data->player->m_speed;
}

void	move_right(t_game_core *game)
{
	if (game->data->map[(int)(game->pj->y
			+ cos(game->pj->pangle) * 5 * game->data->player->m_speed) / 16]
		[(int)(game->pj->x) / 16] == '0')
		game->pj->y += cos(game->pj->pangle) * 5 * game->data->player->m_speed;
	if (game->data->map[(int)(game->pj->y) / 16]
		[(int)(game->pj->x - sin(game->pj->pangle)
			* 5 * game->data->player->m_speed) / 16] == '0')
		game->pj->x -= sin(game->pj->pangle) * 5 * game->data->player->m_speed;
}
