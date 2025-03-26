/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:22:37 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/27 13:06:51 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	ft_init_data(t_data *data)
{
	data->width = 1920;
	data->height = 1080;
	data->sky = 0;
	data->floor = 0;
	data->text_paths.east = NULL;
	data->text_paths.north = NULL;
	data->text_paths.south = NULL;
	data->text_paths.west = NULL;
	data->n_wall = NULL;
	data->s_wall = NULL;
	data->e_wall = NULL;
	data->w_wall = NULL;
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		ft_errors(data, ERR_SYS, NULL);
	data->animcounter = 0;
}

static void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->width, data->height, "cub3D", false);
	if (!data->mlx)
		ft_errors(data, ERR_MLX, NULL);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		ft_errors(data, ERR_MLX, NULL);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		ft_errors(data, ERR_MLX, NULL);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	data->mousex = 0;
}

static char	*ft_clean_textures(char *texture)
{
	char	*remove;

	if (texture)
	{
		remove = ft_strtrim(texture, " ");
		free(texture);
		return (remove);
	}
	return (NULL);
}

static void	ft_load_textures(t_data *data)
{
	data->e_wall = mlx_load_png(data->text_paths.east);
	data->n_wall = mlx_load_png(data->text_paths.north);
	data->s_wall = mlx_load_png(data->text_paths.south);
	data->w_wall = mlx_load_png(data->text_paths.west);
	if (!data->e_wall || !data->n_wall || !data->s_wall || !data->w_wall)
		ft_errors(data, ERR_MLX, NULL);
	data->texture_buffer[0] = data->e_wall->pixels;
	data->texture_buffer[1] = data->n_wall->pixels;
	data->texture_buffer[2] = data->s_wall->pixels;
	data->texture_buffer[3] = data->w_wall->pixels;
}

void	ft_init(t_data *data, char *file)
{
	ft_init_data(data);
	ft_init_mlx(data);
	ft_main_parser(data, file);
	data->text_paths.east = ft_clean_textures(data->text_paths.east);
	data->text_paths.north = ft_clean_textures(data->text_paths.north);
	data->text_paths.south = ft_clean_textures(data->text_paths.south);
	data->text_paths.west = ft_clean_textures(data->text_paths.west);
	ft_texture_check(data);
	ft_load_textures(data);
	ft_map_check(data);
	ft_load_animation(data);
}
