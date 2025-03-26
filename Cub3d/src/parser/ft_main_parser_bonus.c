/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:22:37 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/27 13:26:36 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	color_counter(char **rgb, char **aux, t_data *data)
{
	int	i;
	int	colors;

	i = 0;
	colors = 0;
	while (rgb[i])
	{
		if (rgb[i][0] != '\n' && ft_is_str_num(rgb[i]))
			colors++;
		i++;
	}
	if (colors < 3 && aux[0][0] != '\n')
	{
		ft_clean_array(rgb);
		ft_clean_array(aux);
		ft_errors(data, ERR_COLOR, "Invalid or missing color");
	}
}

void	ft_set_colors(t_data *data, char **aux)
{
	uint8_t		col[3];
	char		**rgb;
	int			i;

	rgb = ft_split(aux[1], ',');
	if (!rgb)
		ft_errors(data, ERR_COLOR, "Invalid or missing color");
	color_counter(rgb, aux, data);
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			ft_errors(data, ERR_COLOR, "Invalid or missing color");
		col[i] = ft_atoi(rgb[i]);
	}
	if (aux[0][0] == 'F')
		data->floor = col[0] << 24 | col[1] << 16 | col[2] << 8 | 0x000000FF;
	else
		data->sky = col[0] << 24 | col[1] << 16 | col[2] << 8 | 0x000000FF;
	ft_clean_array(rgb);
}

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

void	ft_main_parser(t_data *data, char *file)
{
	char	**map;
	int		fd;
	int		i;

	i = count_lines(file);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		ft_errors(data, ERR_SYS, NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	map[i] = ft_parse_textures(data, fd);
	if (fd < 0 || !map[i])
		ft_errors(data, ERR_CUST, "Invalid map or fd\n");
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) == 1 && map[i][0] == '\n')
			ft_errors(data, ERR_CUST, "Map can't have empty line/s\n");
		i++;
		map[i] = get_next_line(fd);
	}
	if (map[i] && map[i][0] == '\n')
		free(map[i]);
	data->map = map;
	ft_player_coords(data, map);
	ft_map_check(data);
}
