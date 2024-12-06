/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:42:01 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/06 04:04:11 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int esc_hook(t_data *data) {
  write(1, "game over!!!\n", 13);
  mlx_destroy_image(data->game.mlx, data->game.img.img_ptr);
  mlx_destroy_window(data->game.mlx, data->game.win);
  // macos
#ifdef __linux__
  mlx_destroy_display(data->game.mlx);
#endif
  squeaky_clean(data);
  exit(0);
}

int ft_key_press(int key, t_data *data) {
  if (key == ESC)
    esc_hook(data);
  if (key == W)
    data->game.player.key_up = 1;
  if (key == S)
    data->game.player.key_down = 1;
  if (key == A)
    data->game.player.key_left = 1;
  if (key == D)
    data->game.player.key_right = 1;
  if (key == LEFT)
    data->game.player.left_rotate = 1;
  if (key == RIGHT)
    data->game.player.right_rotate = 1;
  return (0);
}

int ft_key_release(int key, t_data *data) {
  if (key == W)
    data->game.player.key_up = 0;
  if (key == S)
    data->game.player.key_down = 0;
  if (key == A)
    data->game.player.key_left = 0;
  if (key == D)
    data->game.player.key_right = 0;
  if (key == LEFT)
    data->game.player.left_rotate = 0;
  if (key == RIGHT)
    data->game.player.right_rotate = 0;
  return (0);
}
