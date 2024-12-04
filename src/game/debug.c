/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:44:28 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/04 13:36:15 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(int x, int y, int size, t_game *game)
{
	int	i;
	int	k;
	int	color;

	color = 0xffff;
	i = 0;
	k = 0;
	while (i < size)
	{
		k = 0;
		while (k < size)
		{
			my_pixel_put(&game->img, x + i, y + k, color);
			k++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int		y;
	int		x;
	char	**map;

	map = data->map.map_tab;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, &data->game);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->game.mlx,
		data->game.win,
		data->game.img.img_ptr,
		0, 0);
}
