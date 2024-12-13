/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:09:56 by bsengeze          #+#    #+#             */
/*   Updated: 2024/12/13 07:10:32 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_textures *textures)
{
	int	i;

	i = 0;
	textures->path_n = NULL;
	textures->path_s = NULL;
	textures->path_w = NULL;
	textures->path_e = NULL;
	textures->tex_n = NULL;
	textures->tex_s = NULL;
	textures->tex_w = NULL;
	textures->tex_e = NULL;
	textures->tex = malloc(sizeof(t_tex_img *) * 4);
	if (textures->tex)
	{
		while (i < 4)
			textures->tex[i++] = NULL;
	}
	textures->floor = NULL;
	textures->ceiling = NULL;
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map_tab = NULL;
	map->not_surrounded = 0;
	map->player_count = 0;
}
