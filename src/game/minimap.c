/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:15:25 by bsengeze          #+#    #+#             */
/*   Updated: 2024/12/07 23:01:36 by bsengeze         ###   ########.fr       */
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

static void	draw_player_dot(t_data *data, float px, float py)
{
	int	x;
	int	y;

	y = -2;
	while (y <= 2)
	{
		x = -2;
		while (x <= 2)
		{
			if (px + x < WIDTH && py + y < HEIGHT)
				my_pixel_put(&data->game.img, px + x, py + y, 0xFF0000);
			x++;
		}
		y++;
	}
}

static void	draw_direction_line(t_data *data, float px, float py)
{
	float	dir_len;
	int		i;
	int		line_x;
	int		line_y;

	dir_len = 7.0;
	i = 0;
	while (i < dir_len)
	{
		line_x = px + (cos(data->game.player.angle) * i);
		line_y = py + (sin(data->game.player.angle) * i);
		if (line_x < WIDTH && line_y < HEIGHT)
			my_pixel_put(&data->game.img, line_x, line_y, 0xFF0000);
		i++;
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
