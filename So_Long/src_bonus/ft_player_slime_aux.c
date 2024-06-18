/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_slime_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:42:40 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/18 11:42:09 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_aux_render_player(t_data *data, t_anim *player)
{
	if (mlx_image_to_window(data->mlx, player->up,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, player->down,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, player->left,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, player->right,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	return (1);
}

int	ft_aux_render_slime(t_data *data, int i)
{
	if (mlx_image_to_window(data->mlx, data->slime[i]->up,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->slime[i]->down,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->slime[i]->left,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->slime[i]->right,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	return (1);
}
