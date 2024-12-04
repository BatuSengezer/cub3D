/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:06 by joschka           #+#    #+#             */
/*   Updated: 2024/12/04 19:42:59 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize(t_data *data)
{
	data->game.mlx = mlx_init();
	data->game.win = mlx_new_window(data->game.mlx, WIDTH, HEIGHT, "Cub3d");
	data->game.img.img_ptr = mlx_new_image(data->game.mlx, WIDTH, HEIGHT);
	data->game.img.img_pixels_ptr = mlx_get_data_addr(data->game.img.img_ptr,
			&data->game.img.bits_per_pixel,
			&data->game.img.line_len,
			&data->game.img.endian);
	get_player_pos(data);
}

int	collision(t_data *data, int x, int y)
{
	int		px;
	int		py;
	char	**map;

	map = data->map.map_tab;
	px = x / BLOCK;
	py = y / BLOCK;
	// if (px < 0 || py < 0 || px + 32 >= HEIGHT || py + 32 >= WIDTH)
	// 	return (1);
	if (map[py][px] == '1')
		return (1);
	return (0);
}

void	draw_rays(int x, int y, int color, t_data *data)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	float	fraction = PI / 3 / WIDTH;
	float	start_x = data->game.player.angle - PI / 6;
	int		i = 0;

	while (i < WIDTH)
	{
		cos_angle = cos(start_x);
		sin_angle = sin(start_x);
		ray_y = y + 2.5;
		ray_x = x + 2.5;
		while (!collision(data, ray_x, ray_y))
		{
			my_pixel_put(&data->game.img, ray_x, ray_y, color);
			ray_x += cos_angle * 0.5;
			ray_y += sin_angle * 0.5;
		}
		start_x += fraction;
		i++;
	}
}

int	draw_loop(t_data *data)
{
	move_player(&data->game.player);
	clear_image(&data->game.img);
	if (DEBUG)
	{
		draw_map(data);
		draw_square(data->game.player.x, data->game.player.y, 5, &data->game);
		draw_rays(data->game.player.x, data->game.player.y, 0x00ff, data);
	}
	mlx_put_image_to_window(data->game.mlx,
		data->game.win,
		data->game.img.img_ptr,
		0, 0);
	return (0);
}

void	game(t_data *data)
{
	initialize(data);
	mlx_hook(data->game.win, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->game.win, 3, 1L << 1, ft_key_release, data);
	mlx_hook(data->game.win, 17, 0, esc_hook, data);
	mlx_loop_hook(data->game.mlx, draw_loop, data);
	mlx_loop(data->game.mlx);
}
