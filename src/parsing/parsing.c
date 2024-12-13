/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:00:57 by joschka           #+#    #+#             */
/*   Updated: 2024/12/07 01:51:27 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_cub_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'b' || path[len - 2] != 'u' || path[len - 3] != 'c'
		|| path[len - 4] != '.')
		return (1);
	return (0);
}

static int	check_cub_file(char *path)
{
	int	fd;

	// fd = open(path, __O_DIRECTORY);
	fd = open(path, O_DIRECTORY); // macos
	if (fd > 0)
	{
		close(fd);
		return (print_error(path, ERR_DIR, 1));
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno), errno));
	close(fd);
	if (check_cub_extension(path))
		return (print_error(path, ERR_CUB, 1));
	return (0);
}

int	parsing(char *path, t_data *data)
{
	if (check_cub_file(path))
		return (1);
	data->scenery.s_path = path;
	if (get_scene(&data->scenery))
		return (1);
	if (check_elements(data->scenery.scene) || map_last(data->scenery.scene)
		|| get_textures(data) || get_colors(data) || get_map(data)
		|| check_map(&data->map))
	{
		squeaky_clean(data);
		return (1);
	}
	return (0);
}
