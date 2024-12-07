/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:56:47 by joschka           #+#    #+#             */
/*   Updated: 2024/12/07 01:51:29 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_scenery(t_scenery *scenery)
{
	scenery->scene = NULL;
	scenery->s_path = NULL;
	scenery->lcount = 0;
	scenery->fd = 0;
}

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

void	init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->img_pixels_ptr = NULL;
	img->bits_per_pixel = 0;
	img->endian = 0;
	img->line_len = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->angle = 0;
	player->speed = 15;
	player->angle_speed = 0.1;
	player->key_up = 0;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->left_rotate = 0;
	player->right_rotate = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	init_img(&game->img);
	init_player(&game->player);
	game->wall_collision = 0;
}

void	init(t_data *data)
{
	init_scenery(&data->scenery);
	init_textures(&data->textures);
	init_map(&data->map);
	init_game(&data->game);
}
