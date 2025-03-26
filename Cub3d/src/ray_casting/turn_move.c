/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:56:04 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/19 17:56:30 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
