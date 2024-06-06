/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:50:47 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/06 12:38:23 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

int	ft_render_enemies(t_data *data)
{
	ft_start_pos(data);
	if (!data->textures->player)
		return (EXIT_FAILURE);
	data->player = mlx_texture_to_image(data->mlx, data->textures->player);
	if (!data->player)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->player,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	data->player->instances[0].enabled = 1;
	return (0);
}