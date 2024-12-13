/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:15:25 by bsengeze          #+#    #+#             */
/*   Updated: 2024/12/13 07:07:54 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_border(t_data *data, int start_x, int start_y, int size)
{
	int	x;
	int	y;
	int	map_height;
	int	map_width;

	map_width = data->map.width * (size / data->map.width);
	map_height = data->map.height * (size / data->map.width);
	y = 0;
	while (y < map_height + 2)
	{
		x = 0;
		while (x < map_width + 2)
		{
			if (start_x + x < WIDTH && start_y + y < HEIGHT)
				my_pixel_put(&data->game.img, start_x + x, start_y + y,
					0xFFFFFF);
			x++;
		}
		y++;
	}
}

static void	draw_background(t_data *data, int start_x, int start_y, int size)
{
	int	x;
	int	y;
	int	map_height;
	int	map_width;

	map_width = data->map.width * (size / data->map.width);
	map_height = data->map.height * (size / data->map.width);
	y = 1;
	while (y < map_height + 1)
	{
		x = 1;
		while (x < map_width + 1)
		{
			if (start_x + x < WIDTH && start_y + y < HEIGHT)
				my_pixel_put(&data->game.img, start_x + x, start_y + y,
					0x444444);
			x++;
		}
		y++;
	}
}

static void	draw_wall_block(t_data *data, int x, int y, int size)
{
	int	bx;
	int	by;

	by = 0;
	while (by < size)
	{
		bx = 0;
		while (bx < size)
		{
			if (x + bx < WIDTH && y + by < HEIGHT)
				my_pixel_put(&data->game.img, x + bx, y + by, 0xFFFFFF);
			bx++;
		}
		by++;
	}
}

static void	draw_map_walls(t_data *data, int start_x, int start_y, int b_size)
{
	int	x;
	int	y;
	int	block_x;
	int	block_y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.map_tab[y][x] == '1')
			{
				block_x = start_x + (x * b_size);
				block_y = start_y + (y * b_size);
				draw_wall_block(data, block_x, block_y, b_size);
			}
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int		map_size;
	int		block_size;
	int		start_x;
	int		start_y;
	float	player_pos[2];

	map_size = 150;
	block_size = map_size / data->map.width;
	start_x = WIDTH - (data->map.width * block_size) - 10;
	start_y = 10;
	draw_border(data, start_x, start_y, map_size);
	draw_background(data, start_x, start_y, map_size);
	draw_map_walls(data, start_x + 1, start_y + 1, block_size);
	player_pos[0] = start_x + ((data->game.player.x / BLOCK) * block_size);
	player_pos[1] = start_y + ((data->game.player.y / BLOCK) * block_size);
	draw_player_dot(data, player_pos[0], player_pos[1]);
	draw_direction_line(data, player_pos[0], player_pos[1]);
}
