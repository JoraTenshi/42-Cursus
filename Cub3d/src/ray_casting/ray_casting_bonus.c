/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:52:39 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/21 13:49:23 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	find_color(t_game_core *game, int tx, int ty, int side)
{
	int	r;
	int	g;
	int	b;

	r = game->data->texture_buffer[side][(int)(ty * 64 + tx) *4];
	g = game->data->texture_buffer[side][(int)(ty * 64 + tx) *4 + 1];
	b = game->data->texture_buffer[side][(int)(ty * 64 + tx) *4 + 2];
	return (get_rgba(r, g, b, 255));
}

static void	ft_next_ray_dir(t_game_core *game, t_ray *ray)
{
	ray->rangle += ((DR * 80) / game->data->width);
	if (ray->rangle < 0)
		ray->rangle += 2 * PI;
	if (ray->rangle > 2 * PI)
		ray->rangle -= 2 * PI;
}

static void	ft_shortest_ray(t_ray *ray)
{
	if (ray->dis_v < ray->dis_h)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->total_dis = ray->dis_v;
		ray->v_h = 0;
	}
	else if (ray->dis_v > ray->dis_h)
	{
		ray->ry = ray->hy;
		ray->rx = ray->hx;
		ray->total_dis = ray->dis_h;
		ray->v_h = 1;
	}
}

void	draw_rays(t_game_core *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		exit(1);
	ray->hx = ray->rx;
	ray->hy = ray->ry;
	ray->rangle = game->pj->pangle - (DR * 40);
	ray->count = -1;
	ray->v_h = 0;
	while (++ray->count < game->data->width)
	{
		ray->dis_h = 1000000;
		ray->dis_v = 1000000;
		ray->dof = 0;
		ft_horizontal_lines(game, ray);
		ray->dof = 0;
		ray->vx = ray->rx;
		ray->vy = ray->ry;
		ft_vertical_lines(game, ray);
		ft_shortest_ray(ray);
		ft_manage_3d_walls(game, ray);
		ft_next_ray_dir(game, ray);
	}
	free(ray);
}
//ft_restart_angle(ray);
//draw_ray_line(game->img, game->pj, ray, -1);
