/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:26:39 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/27 12:10:19 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_close(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_exit((t_data *)param, EXIT_SUCCESS);
}

void	ft_clean_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	ft_clean(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->map)
		ft_clean_array(data->map);
	if (data->n_wall)
		mlx_delete_texture(data->n_wall);
	if (data->s_wall)
		mlx_delete_texture(data->s_wall);
	if (data->e_wall)
		mlx_delete_texture(data->e_wall);
	if (data->w_wall)
		mlx_delete_texture(data->w_wall);
	if (data->text_paths.east)
		free(data->text_paths.east);
	if (data->text_paths.north)
		free(data->text_paths.north);
	if (data->text_paths.south)
		free(data->text_paths.south);
	if (data->text_paths.west)
		free(data->text_paths.west);
}

void	ft_exit(t_data *data, int status)
{
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	ft_clean(data);
	exit(status);
}

void	ft_errors(t_data *data, int error, char *msg)
{
	printf(RED);
	if (error == ERR_CUST)
		printf("%s\n", msg);
	else if (error == ERR_SYS)
		printf("Error: System error\n");
	else if (error == ERR_FD)
		printf("Error: File descriptor error\n");
	else if (error == ERR_TEXT)
		printf("%s\n", msg);
	else if (error == ERR_COLOR)
		printf("%s\n", msg);
	else if (error == ERR_MLX)
		printf("MLX Error: %s", mlx_strerror(mlx_errno));
	else if (error == ERR_ARGC)
		printf("MLX Error: %s", mlx_strerror(mlx_errno));
	else if (error == ERR_EXT)
		printf("Error: Invalid file extension\n");
	printf(DEFAULT);
	ft_exit(data, EXIT_FAILURE);
}
