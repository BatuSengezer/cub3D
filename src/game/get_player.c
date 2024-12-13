/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:01:08 by bsengeze          #+#    #+#             */
/*   Updated: 2024/12/13 07:01:41 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
