/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:44:23 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/13 07:01:20 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_player *player)
{
	if (player->left_rotate)
		player->angle -= player->angle_speed;
	if (player->right_rotate)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

static void	calculate_movement(t_player *player, t_angle angle, float *new_x,
		float *new_y)
{
	if (player->key_up)
	{
		*new_x += angle.cos * player->speed;
		*new_y += angle.sin * player->speed;
	}
	if (player->key_down)
	{
		*new_x -= angle.cos * player->speed;
		*new_y -= angle.sin * player->speed;
	}
	if (player->key_left)
	{
		*new_x += angle.sin * player->speed;
		*new_y -= angle.cos * player->speed;
	}
	if (player->key_right)
	{
		*new_x -= angle.sin * player->speed;
		*new_y += angle.cos * player->speed;
	}
}

void	move(t_player *player, t_data *data)
{
	t_angle	angle;
	float	new_x;
	float	new_y;

	angle.cos = cos(player->angle);
	angle.sin = sin(player->angle);
	new_x = player->x;
	new_y = player->y;
	calculate_movement(player, angle, &new_x, &new_y);
	if (!collision(data, new_x, new_y))
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	move_player(t_player *player, t_data *data)
{
	rotate(player);
	move(player, data);
}
