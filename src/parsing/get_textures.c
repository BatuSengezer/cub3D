/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:43:40 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/13 06:51:39 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->textures.tex_n = load_texture(data->game.mlx,
			data->textures.path_n[1]);
	if (!data->textures.tex_n)
		return (1);
	data->textures.tex_s = load_texture(data->game.mlx,
			data->textures.path_s[1]);
	if (!data->textures.tex_s)
		return (1);
	data->textures.tex_e = load_texture(data->game.mlx,
			data->textures.path_e[1]);
	if (!data->textures.tex_e)
		return (1);
	data->textures.tex_w = load_texture(data->game.mlx,
			data->textures.path_w[1]);
	if (!data->textures.tex_w)
		return (1);
	data->textures.tex[0] = data->textures.tex_n;
	data->textures.tex[1] = data->textures.tex_s;
	data->textures.tex[2] = data->textures.tex_e;
	data->textures.tex[3] = data->textures.tex_w;
	return (0);
}
