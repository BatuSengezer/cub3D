/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:05:15 by bsengeze          #+#    #+#             */
/*   Updated: 2024/12/13 07:09:05 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_direction_line(t_data *data, float px, float py)
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

void	draw_player_dot(t_data *data, float px, float py)
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
