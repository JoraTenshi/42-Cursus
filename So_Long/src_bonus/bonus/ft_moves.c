/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:51:15 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/06 10:49:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_moves(t_data *data)
{
	char	*mov;

	if (data->wmoves)
		mlx_delete_image(data->mlx, data->wmoves);
	mov = ft_itoa(data->moves);
	data->wmoves = mlx_put_string(data->mlx, mov, 16, 16);
	free (mov);
}
