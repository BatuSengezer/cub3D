/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_and_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:32 by joschka           #+#    #+#             */
/*   Updated: 2024/12/06 23:22:01 by bsengeze         ###   ########.fr       */
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
	if (data->scenery.scene)
		free_array(data->scenery.scene);
	/*
	if (data->textures.path_n)
			free_array(data->textures.path_n);
	if (data->textures.path_s)
			free_array(data->textures.path_s);
	if (data->textures.path_w)
			free_array(data->textures.path_w);
	if (data->textures.path_e)
			free_array(data->textures.path_e);
	*/
	if (data->textures.floor)
		free(data->textures.floor);
	if (data->textures.ceiling)
		free(data->textures.ceiling);
	if (data->map.map_tab)
		free_array(data->map.map_tab);
	if (data->game.mlx)
		free(data->game.mlx);
	cleanup_textures(data);
}

void	cleanup_textures(t_data *data)
{
	if (!data->game.mlx)
		return ;
	if (data->textures.tex)
	{
		free(data->textures.tex);
		data->textures.tex = NULL;
	}
	// Free texture paths
	if (data->textures.path_n)
		free_array(data->textures.path_n);
	if (data->textures.path_s)
		free_array(data->textures.path_s);
	if (data->textures.path_w)
		free_array(data->textures.path_w);
	if (data->textures.path_e)
		free_array(data->textures.path_e);
	// Free texture images
	if (data->textures.tex_n)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_n->img);
		free(data->textures.tex_n);
	}
	if (data->textures.tex_s)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_s->img);
		free(data->textures.tex_s);
	}
	if (data->textures.tex_e)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_e->img);
		free(data->textures.tex_e);
	}
	if (data->textures.tex_w)
	{
		mlx_destroy_image(data->game.mlx, data->textures.tex_w->img);
		free(data->textures.tex_w);
	}
	if (data->textures.tex)
		free(data->textures.tex);
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
