/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:15:02 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/21 13:37:29 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_background(t_game_core *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->data->width)
	{
		j = -1;
		while (++j < game->data->height)
		{
			if (j < (game->data->height / 2))
				mlx_put_pixel(game->img, i, j, game->data->sky);
			else
				mlx_put_pixel(game->img, i, j, game->data->floor);
		}
	}
}

static void	ft_refresh_half_screen(t_game_core *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->data->height)
	{
		j = 0;
		while (j < game->data->width)
		{
			mlx_put_pixel(game->img, j, i, 0);
			j++;
		}
		i++;
	}
}

void	ft_draw_2d(void *param)
{
	t_game_core	*game;

	game = (t_game_core *)param;
	ft_refresh_half_screen(game);
	draw_background(game);
	draw_rays(game);
}
