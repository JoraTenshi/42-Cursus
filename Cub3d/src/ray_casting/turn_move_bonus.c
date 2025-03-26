/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:56:04 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/21 13:49:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	turn_left(t_game_core *game)
{
	game->pj->pangle -= 0.1;
	if (game->pj->pangle < 0)
		game->pj->pangle += 2 * PI;
	game->pj->pdx = cos(game->pj->pangle) * 5;
	game->pj->pdy = sin(game->pj->pangle) * 5;
}

void	turn_right(t_game_core *game)
{
	game->pj->pangle += 0.1;
	if (game->pj->pangle > 2 * PI)
		game->pj->pangle -= 2 * PI;
	game->pj->pdx = cos(game->pj->pangle) * 5;
	game->pj->pdy = sin(game->pj->pangle) * 5;
}
