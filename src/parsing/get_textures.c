/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:43:40 by jbeck             #+#    #+#             */
/*   Updated: 2024/11/21 14:41:55 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'm' || path[len - 2] != 'p'
		|| path[len - 3] != 'x' || path[len - 4] != '.')
		return (1);
	return (0);
}

static int	check_xpm_file(char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (print_error(path, ERR_DIR, 1));
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno), errno));
	close(fd);
	if (check_xpm_extension(path))
		return (print_error(path, ERR_XPM, 1));
	return (0);
}

static int	check_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (i == 1)
			cut_newline(arr);
		if (i == 1 && check_xpm_file(arr[i]))
			return (1);
		i++;
	}
	if (i == 1)
		return (print_error(arr[0], ERR_TEX, 1));
	if (i > 2)
		return (print_error(arr[0], ERR_TEXT, 1));
	return (0);
}

static int	save_texture(char *str, char ***arr)
{
	if (*arr)
		free_array(*arr);
	*arr = ft_split(str, ' ');
	if (!*arr)
		return (1);
	if (check_array(*arr))
		return (1);
	return (0);
}

int	get_textures(t_data *data)
{
	char	**arr;
	int		i;
	int		ret;
	int		j;

	i = 0;
	ret = 0;
	j = 0;
	arr = data->scenery.scene;
	while (arr[i])
	{
		if (ret)
			break ;
		j = skip_space(arr[i]);
		if (!ft_strncmp(&arr[i][j], "NO", 2) && !ret)
			ret = save_texture(arr[i], &data->textures.north);
		if (!ft_strncmp(&arr[i][j], "SO", 2) && !ret)
			ret = save_texture(arr[i], &data->textures.south);
		if (!ft_strncmp(&arr[i][j], "EA", 2) && !ret)
			ret = save_texture(arr[i], &data->textures.east);
		if (!ft_strncmp(&arr[i][j], "WE", 2) && !ret)
			ret = save_texture(arr[i], &data->textures.west);
		i++;
	}
	return (ret);
}
