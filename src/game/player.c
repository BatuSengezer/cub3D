/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:44:23 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/04 16:20:39 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	get_player_angle(char c, t_player *player)
{
	if (c == 'N')
		player->angle = (3 * PI) / 2;
	if (c == 'S')
		player->angle = PI / 2;
	if (c == 'E')
		player->angle = 2 * PI;
	if (c == 'W')
		player->angle = PI;
}

void	get_player_pos(t_data *data)
{
	int		i;
	int		k;
	char	c;

	i = 0;
	while (data->map.map_tab[i])
	{
		k = 0;
		while (data->map.map_tab[i][k])
		{
			c = data->map.map_tab[i][k];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				data->game.player.x = k * BLOCK + (BLOCK / 2);
				data->game.player.y = i * BLOCK + (BLOCK / 2);
				get_player_angle(c, &data->game.player);
			}
			k++;
		}
		i++;
	}
}

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

void	move(t_player *player, t_data *data)
{
	float	cos_angle;
	float	sin_angle;
	float	new_x;
	float	new_y;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	
	new_x = player->x;
	new_y = player->y;
	
	if (player->key_up)
	{
		new_x += cos_angle * player->speed;
		new_y += sin_angle * player->speed;
	}
	if (player->key_down)
	{
		new_x -= cos_angle * player->speed;
		new_y -= sin_angle * player->speed;
	}
	if (player->key_left)
	{
		new_x += sin_angle * player->speed;
		new_y -= cos_angle * player->speed;
	}
	if (player->key_right)
	{
		new_x -= sin_angle * player->speed;
		new_y += cos_angle * player->speed;
	}
	
	// Not checking for collision here caused wall problems
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
