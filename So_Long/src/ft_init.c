/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:35:56 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/20 10:50:35 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_init(t_data *data)
{
	data->mlx = NULL;
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->size_x = 0;
	data->size_y = 0;
	data->moves = 0;
	data->p_collectibles = 0;
	data->t_collectibles = 0;
	data->player = NULL;
	data->textures = NULL;
	data->collectible_images = NULL;
	data->exit_image = NULL;
	data->key_pressed = 0;
	data->end = 0;
}
