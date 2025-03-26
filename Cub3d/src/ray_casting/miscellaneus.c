/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:36:27 by aarenas-          #+#    #+#             */
/*   Updated: 2025/02/20 12:24:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	ft_search_start(t_game_core *game)
{
	int			i;
	int			j;
	char		start_pos;

	i = -1;
	while (++i < game->data->map_longest_row)
	{
		j = -1;
		while (++j < game->data->map_rows)
		{
			if (game->data->map[j][i] == 'S' || game->data->map[j][i] == 'E'
				|| game->data->map[j][i] == 'W' || game->data->map[j][i] == 'N')
			{
				start_pos = game->data->map[j][i];
				game->data->map[j][i] = '0';
				return (start_pos);
			}
		}
	}
	return (0);
}

double	ft_find_dir(t_game_core *game)
{
	char	start_pos;

	start_pos = ft_search_start(game);
	if (start_pos == '\0')
		exit(1);
	if (start_pos == 'S')
		return (PI / 2);
	else if (start_pos == 'N')
		return ((3 * PI) / 2);
	else if (start_pos == 'W')
		return (PI);
	else
		return (2 * PI);
}

float	ft_distance(t_game_core *game, float end_x, float end_y)
{
	return (sqrt((end_x - game->pj->x) * (end_x - game->pj->x)
			+ (end_y - game->pj->y) * (end_y - game->pj->y)));
}

int	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 1)
	{
		printf("Error: gettimeofday() failed\n");
		exit(1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_init_data_pj(t_game_core *game, t_player *pj, mlx_image_t *img)
{
	pj->x = (game->data->player->start_x * 16);
	pj->y = (game->data->player->start_y * 16);
	game->pj = pj;
	game->img = img;
	game->xh_limit = game->data->width;
	game->yh_limit = game->data->width;
	game->xv_limit = 0;
	game->yv_limit = 0;
	game->last_time = ft_get_time();
	game->delay = 33;
	game->pj->pangle = ft_find_dir(game);
	game->pj->pdx = cos(game->pj->pangle) * 5;
	game->pj->pdy = sin(game->pj->pangle) * 5;
}
