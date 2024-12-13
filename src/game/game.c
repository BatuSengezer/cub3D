/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:06 by joschka           #+#    #+#             */
/*   Updated: 2024/12/13 14:10:13 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize(t_data *data)
{
	data->game.mlx = mlx_init();
	data->game.win = mlx_new_window(data->game.mlx, WIDTH, HEIGHT, "Cub3d");
	data->game.img.img_ptr = mlx_new_image(data->game.mlx, WIDTH, HEIGHT);
	data->game.img.img_pixels_ptr = mlx_get_data_addr(data->game.img.img_ptr,
			&data->game.img.bits_per_pixel, &data->game.img.line_len,
			&data->game.img.endian);
	if (load_all_textures(data))
	{
		print_error(NULL, ERR_TEXTURE, 1);
		clean_exit(data, 1);
	}
	get_player_pos(data);
}

int	draw_loop(t_data *data)
{
	move_player(&data->game.player, data);
	clear_image(&data->game.img);
	raycasting(data->game.player.x, data->game.player.y, data);
	mlx_put_image_to_window(data->game.mlx, data->game.win,
		data->game.img.img_ptr, 0, 0);
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
