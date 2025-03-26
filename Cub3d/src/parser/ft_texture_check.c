/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:38:37 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/27 13:29:31 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_aux_trim(t_data *data, char **arr, char *line)
{
	char	*temp;

	temp = ft_strtrim(arr[1], "\n");
	if (!ft_strncmp(line, "NO ", 3))
		data->text_paths.north = ft_strdup(temp);
	else if (!ft_strncmp(line, "SO ", 3))
		data->text_paths.south = ft_strdup(temp);
	else if (!ft_strncmp(line, "WE ", 3))
		data->text_paths.west = ft_strdup(temp);
	else if (!ft_strncmp(line, "EA ", 3))
		data->text_paths.east = ft_strdup(temp);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		ft_set_colors(data, arr);
	free(temp);
	ft_clean_array(arr);
}

void	ft_texture_check(t_data *data)
{
	int	fd;

	if (!data->text_paths.east || !data->text_paths.north
		|| !data->text_paths.south || !data->text_paths.west)
		ft_errors(data, ERR_CUST, "Missing or misplaced textures");
	fd = open(data->text_paths.east, O_RDONLY);
	if (fd < 0)
		ft_errors(data, ERR_CUST, "Invalid east fd");
	close(fd);
	fd = open(data->text_paths.north, O_RDONLY);
	if (fd < 0)
		ft_errors(data, ERR_CUST, "Invalid north fd");
	close(fd);
	fd = open(data->text_paths.south, O_RDONLY);
	if (fd < 0)
		ft_errors(data, ERR_CUST, "Invalid south fd");
	close(fd);
	fd = open(data->text_paths.west, O_RDONLY);
	if (fd < 0)
		ft_errors(data, ERR_CUST, "Invalid west fd");
	close(fd);
	if (!data->floor)
		ft_errors(data, ERR_CUST, "Invalid floor color");
	if (!data->sky)
		ft_errors(data, ERR_CUST, "Invalid sky color");
}

static void	save_textures(t_data *data, char *line)
{
	char	**aux;
	int		len;

	len = 0;
	aux = ft_split(line, ' ');
	if (!aux)
	{
		ft_clean_array(aux);
		ft_errors(data, ERR_SYS, NULL);
	}
	while (aux[len])
		len++;
	if (len <= 1 && aux[0][0] != '\n')
		ft_errors(data, ERR_TEXT, "Error: no texture");
	if (aux && aux[0][0] != '\n')
		ft_aux_trim(data, aux, line);
	else
		ft_clean_array(aux);
}

char	*ft_parse_textures(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
			|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2)
			|| !ft_strncmp(line, "\n", 1)))
	{
		if (!ft_strncmp(line, "NO ", 3) && data->text_paths.north)
			ft_errors(data, ERR_TEXT, "Error: north wall texture duplicated");
		if (!ft_strncmp(line, "SO ", 3) && data->text_paths.south)
			ft_errors(data, ERR_TEXT, "Error: south wall texture duplicated");
		if (!ft_strncmp(line, "WE ", 3) && data->text_paths.west)
			ft_errors(data, ERR_TEXT, "Error: west wall texture duplicated");
		if (!ft_strncmp(line, "EA ", 3) && data->text_paths.east)
			ft_errors(data, ERR_TEXT, "Error: east wall texture ducplicated");
		if (!ft_strncmp(line, "F ", 2) && data->floor)
			ft_errors(data, ERR_TEXT, "Error: floor color duplicated");
		if (!ft_strncmp(line, "C ", 2) && data->sky)
			ft_errors(data, ERR_TEXT, "Error: sky color duplicated");
		save_textures(data, line);
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
