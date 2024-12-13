/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_and_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:32 by joschka           #+#    #+#             */
/*   Updated: 2024/12/07 03:03:26 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	clean_exit(t_data *data, int code)
{
	squeaky_clean(data);
	exit(code);
}

void	squeaky_clean(t_data *data)
{
	cleanup_textures(data);
	if (data->scenery.scene)
		free_array(data->scenery.scene);
	if (data->textures.floor)
		free(data->textures.floor);
	if (data->textures.ceiling)
		free(data->textures.ceiling);
	if (data->map.map_tab)
		free_array(data->map.map_tab);
	if (data->game.mlx)
		free(data->game.mlx);
}

void	cleanup_textures(t_data *data)
{
	if (!data || !data->game.mlx)
		return ;
	// Destroy images first
	if (data->textures.tex_n && data->textures.tex_n->img)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_n->img);
		data->textures.tex_n->img = NULL;
	}
	if (data->textures.tex_s && data->textures.tex_s->img)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_s->img);
		data->textures.tex_s->img = NULL;
	}
	if (data->textures.tex_e && data->textures.tex_e->img)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_e->img);
		data->textures.tex_e->img = NULL;
	}
	if (data->textures.tex_w && data->textures.tex_w->img)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_w->img);
		data->textures.tex_w->img = NULL;
	}
	// Free texture structs after destroying images
	if (data->textures.tex_n)
	{
		free(data->textures.tex_n);
		data->textures.tex_n = NULL;
	}
	if (data->textures.tex_s)
	{
		free(data->textures.tex_s);
		data->textures.tex_s = NULL;
	}
	if (data->textures.tex_e)
	{
		free(data->textures.tex_e);
		data->textures.tex_e = NULL;
	}
	if (data->textures.tex_w)
	{
		free(data->textures.tex_w);
		data->textures.tex_w = NULL;
	}
	// Free texture array last
	if (data->textures.tex)
	{
		free(data->textures.tex);
		data->textures.tex = NULL;
	}
}

int	print_error(char *src, char *str, int errcode)
{
	ft_putstr_fd("Error: ", 2);
	if (src)
	{
		ft_putstr_fd(src, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (errcode);
}
