/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:43:40 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/07 01:51:19 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'm' || path[len - 2] != 'p' || path[len - 3] != 'x'
		|| path[len - 4] != '.')
		return (1);
	return (0);
}

static int	check_xpm_file(char *path)
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
			ret = save_texture(arr[i], &data->textures.path_n);
		if (!ft_strncmp(&arr[i][j], "SO", 2) && !ret)
			ret = save_texture(arr[i], &data->textures.path_s);
		if (!ft_strncmp(&arr[i][j], "EA", 2) && !ret)
			ret = save_texture(arr[i], &data->textures.path_e);
		if (!ft_strncmp(&arr[i][j], "WE", 2) && !ret)
			ret = save_texture(arr[i], &data->textures.path_w);
		i++;
	}
	return (ret);
}

t_tex_img	*load_texture(void *mlx, char *path)
{
	t_tex_img	*tex;

	tex = malloc(sizeof(t_tex_img));
	if (!tex)
		return (NULL);
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img)
	{
		free(tex);
		return (NULL);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	return (tex);
}

int	load_all_textures(t_data *data)
{
	// Load North texture
	data->textures.tex_n = load_texture(data->game.mlx,
			data->textures.path_n[1]);
	if (!data->textures.tex_n)
		return (1);
	// Load South texture
	data->textures.tex_s = load_texture(data->game.mlx,
			data->textures.path_s[1]);
	if (!data->textures.tex_s)
		return (1);
	// Load East texture
	data->textures.tex_e = load_texture(data->game.mlx,
			data->textures.path_e[1]);
	if (!data->textures.tex_e)
		return (1);
	// Load West texture
	data->textures.tex_w = load_texture(data->game.mlx,
			data->textures.path_w[1]);
	if (!data->textures.tex_w)
		return (1);
	// Set up the texture array
	data->textures.tex[0] = data->textures.tex_n; // North
	data->textures.tex[1] = data->textures.tex_s; // South
	data->textures.tex[2] = data->textures.tex_e; // East
	data->textures.tex[3] = data->textures.tex_w; // West
	// Debug print
	printf("Texture dimensions:\n");
	printf("North: %dx%d\n", data->textures.tex_n->width,
		data->textures.tex_n->height);
	printf("South: %dx%d\n", data->textures.tex_s->width,
		data->textures.tex_s->height);
	printf("West: %dx%d\n", data->textures.tex_w->width,
		data->textures.tex_w->height);
	printf("East: %dx%d\n", data->textures.tex_e->width,
		data->textures.tex_e->height);
	return (0);
}
