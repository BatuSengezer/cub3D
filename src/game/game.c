/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:06 by joschka           #+#    #+#             */
/*   Updated: 2024/12/03 18:17:47 by jbeck            ###   ########.fr       */
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
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	dst = img->img_pixels_ptr + offset;
	*(unsigned int *)dst = color;
}

int	esc_hook(t_data *data)
{
	write(1, "game over!!!\n", 13);
	mlx_destroy_image(data->game.mlx, data->game.img.img_ptr);
	mlx_destroy_window(data->game.mlx, data->game.win);
	mlx_destroy_display(data->game.mlx);
	squeaky_clean(data);
	exit(0);
}

int	ft_key_press(int key, t_data *data)
{
	// ft_printf("%d\n", key);
	if (key == ESC)
		esc_hook(data);
	if (key == W)
		color_screen(data, 0xff);
	if (key == A)
		color_screen(data, 0xff00);
	mlx_put_image_to_window(data->game.mlx,
		data->game.win,
		data->game.img.img_ptr,
		0, 0);
	return (0);
}

void	game(t_data *data)
{
	initialize(data);
	if (DEBUG)
		draw_map(data);
	mlx_hook(data->game.win, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->game.win, 17, 0, esc_hook, data);
	mlx_loop(data->game.mlx);
}
