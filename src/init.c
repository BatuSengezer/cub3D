/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:56:47 by joschka           #+#    #+#             */
/*   Updated: 2024/11/29 18:06:37 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map_tab = NULL;
	map->not_surrounded = 0;
	map->player_count = 0;
}

void	init_scenery(t_scenery *scenery)
{
	scenery->scene = NULL;
	scenery->s_path = NULL;
	scenery->lcount = 0;
	scenery->fd = 0;
}

void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
}

void	init(t_data *data)
{
	init_scenery(&data->scenery);
	init_textures(&data->textures);
	init_map(&data->map);
}
