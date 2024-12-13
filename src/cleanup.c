/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:13:35 by bsengeze          #+#    #+#             */
/*   Updated: 2024/12/13 07:16:46 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	cleanup_texture_images(t_data *data)
{
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
}

static void	free_texture(t_tex_img **texture)
{
	if (*texture)
	{
		free(*texture);
		*texture = NULL;
	}
}

void	cleanup_textures(t_data *data)
{
	if (!data || !data->game.mlx)
		return ;
	cleanup_texture_images(data);
	free_texture(&data->textures.tex_n);
	free_texture(&data->textures.tex_s);
	free_texture(&data->textures.tex_e);
	free_texture(&data->textures.tex_w);
	if (data->textures.tex)
	{
		free(data->textures.tex);
		data->textures.tex = NULL;
	}
}
