/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:50 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/27 12:45:20 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	find_wall_side(t_game_core *game, t_ray *ray)
{
	if (ray->v_h == 0)
	{
		ray->wall_side = game->pj->y + ray->real_distance * sin(ray->rangle);
		ray->wall_side = ray->wall_side / 16;
	}
	else if (ray->v_h == 1)
	{
		ray->wall_side = game->pj->x + ray->real_distance * cos(ray->rangle);
		ray->wall_side = ray->wall_side / 16;
	}
	ray->wall_side -= floor(ray->wall_side);
	if (ray->wall_side < 0)
		ray->wall_side += 1.0;
	if (ray->wall_side > 1.0)
		ray->wall_side -= 1.0;
	game->data->tx = (int)(ray->wall_side * 64);
	if (game->data->tx >= 64)
		game->data->tx = 63;
	if (game->data->tx < 0)
		game->data->tx = 0;
}

static void	ft_wall_thickness(mlx_image_t *image,
	t_wall *wall, t_ray *ray, t_game_core *game)
{
	int	texture;
	int	tx;
	int	ty;

	texture = 0;
	tx = (int)(game->data->tx);
	ty = (int)(game->data->ty) % 64;
	if (ray->v_h == 0)
	{
		texture = find_color(game, tx, ty, 3);
		if ((ray->rangle <= (PI / 2) || ray->rangle > (3 * PI) / 2))
			texture = find_color(game, tx, ty, 0);
	}
	else if (ray->v_h == 1)
	{
		texture = find_color(game, tx, ty, 2);
		if (ray->rangle < (PI) && ray->rangle > (0))
			texture = find_color(game, tx, ty, 1);
	}
	mlx_put_pixel(image, ray->count, wall->y + wall->y_offset, texture);
}

static void	draw_wall_lines(mlx_image_t *image,
	t_ray *ray, t_wall *wall, t_game_core *game)
{
	float	dx;
	float	dy;
	float	steps;
	float	increment_x;
	float	increment_y;

	find_wall_side(game, ray);
	dx = fabs(ray->rx - wall->x);
	dy = fabs((wall->lineheight) - wall->y);
	steps = fmax(dx, dy);
	increment_x = dx / steps;
	increment_y = dy / steps;
	while (++game->i < steps)
	{
		ft_wall_thickness(image, wall, ray, game);
		if (ray->rx < wall->x)
			wall->x -= increment_x;
		else
			wall->x += increment_x;
		if (wall->lineheight < wall->y)
			wall->y -= increment_y;
		else
			wall->y += increment_y;
		game->data->ty += game->data->ty_step;
	}
}

static void	ft_restart_angle(t_ray *ray)
{
	if (ray->a_cos < 0)
		ray->a_cos += 2 * PI;
	if (ray->a_cos >= 2 * PI)
		ray->a_cos -= 2 * PI;
}

void	ft_manage_3d_walls(t_game_core *game, t_ray *ray)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_wall));
	if (!wall)
		exit(EXIT_FAILURE);
	wall->x = ray->rx;
	wall->y = 0;
	ray->a_cos = ray->rangle - game->pj->pangle;
	ft_restart_angle(ray);
	ray->real_distance = ray->total_dis;
	ray->total_dis = ray->total_dis * cos(ray->a_cos);
	ray->total_dis = fmax(ray->total_dis, 0.0001);
	wall->lineheight = (16 * game->data->height) / ray->total_dis;
	game->data->ty_step = 64 / wall->lineheight;
	game->data->ty_off = 0;
	if (wall->lineheight > game->data->height)
	{
		game->data->ty_off = (wall->lineheight - game->data->height) / 2;
		wall->lineheight = game->data->height;
	}
	wall->y_offset = (game->data->height / 2) - (wall->lineheight / 2);
	game->data->ty = (game->data->ty_step * game->data->ty_off);
	game->i = -1;
	draw_wall_lines(game->img, ray, wall, game);
	free(wall);
}

/* void	draw_ray_line(mlx_image_t *image, t_player *pj, t_ray *ray, int i)
{
	float	dx;
	float	dy;
	float	steps;
	float	increment_x;
	float	increment_y;

	pj->pic_x = pj->x;
	pj->pic_y = pj->y;
	dx = fabs(ray->rx - pj->pic_x);
	dy = fabs(ray->ry - pj->pic_y);
	steps = fmax(dx, dy);
	increment_x = dx / steps;
	increment_y = dy / steps;
	while (++i < steps && pj->pic_x > 0 && pj->pic_x 
	< 1280 && pj->pic_y > 0 && pj->pic_y < 720)
	{
		mlx_put_pixel(image, pj->pic_x, pj->pic_y, get_rgba(165, 51, 255, 255));
		if (ray->rx < pj->x)
			pj->pic_x -= increment_x;
		else
			pj->pic_x += increment_x;
		if (ray->ry < pj->y)
			pj->pic_y -= increment_y;
		else
			pj->pic_y += increment_y;
	}
} */
