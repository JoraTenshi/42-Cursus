/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical_lines_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:55:59 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/21 13:49:17 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	ft_check_cube_hit(t_game_core *game, t_ray *ray)
{
	while (ray->dof < game->data->map_longest_row && ray->ry > 0 && ray->rx > 0)
	{
		ray->mx = (int)ray->rx >> 4;
		ray->my = (int)ray->ry >> 4;
		ray->mp = ray->my * game->data->map_longest_row + ray->mx;
		if (ray->mp > 0 && ray->mp < game->data->map_longest_row
			* game->data->map_rows
			&& game->data->map[ray->my][ray->mx] == '1')
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->dis_v = ft_distance(game, ray->vx, ray->vy);
			ray->dof = game->data->map_longest_row;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
}

static void	ft_looking_straight_up_down(t_game_core *game, t_ray *ray)
{
	if (ray->rangle == 0 || ray->rangle == PI)
	{
		ray->rx = game->pj->x;
		ray->ry = game->pj->y;
		ray->dof = game->data->map_longest_row;
	}
}

static void	ft_looking_left_right(t_game_core *game, t_ray *ray)
{
	float	ntan;

	ntan = -tan(ray->rangle);
	if (ray->rangle > PI / 2 && ray->rangle <= 3 * PI / 2)
	{
		ray->rx = (((int)game->pj->x >> 4) << 4) - 0.0001;
		ray->ry = (game->pj->x - ray->rx) * ntan + game->pj->y;
		ray->xo = -16;
		ray->yo = -ray->xo * ntan;
	}
	if (ray->rangle < PI / 2 || ray->rangle > 3 * PI / 2)
	{
		ray->rx = (((int)game->pj->x >> 4) << 4) + 16;
		ray->ry = (game->pj->x - ray->rx) * ntan + game->pj->y;
		ray->xo = 16;
		ray->yo = -ray->xo * ntan;
	}
}

void	ft_vertical_lines(t_game_core *game, t_ray *ray)
{
	ft_looking_left_right(game, ray);
	ft_looking_straight_up_down(game, ray);
	ft_check_cube_hit(game, ray);
}
