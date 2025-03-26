/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:47:54 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/21 13:49:00 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_animations(t_data *data)
{
	if (data->animcounter < 0.1)
	{
		data->animcounter += data->mlx->delta_time;
		return ;
	}
	else
		data->animcounter = 0;
	data->torch.frame += 1;
	if (data->torch.frame == 10)
		data->torch.frame = 0;
	if (data->torch.frame == 0)
		data->torch.torch[9]->enabled = 0;
	else
		data->torch.torch[data->torch.frame - 1]->enabled = 0;
	data->torch.torch[data->torch.frame]->enabled = 1;
}
