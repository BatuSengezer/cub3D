/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:53:46 by joschka           #+#    #+#             */
/*   Updated: 2024/11/22 11:38:54 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_width(char **arr)
{
	int	i;
	int	j;
	int	max;

	j = 0;
	i = 0;
	max = 0;
	while (arr[i])
	{
		while (arr[i][j] && arr[i][j] != '\n')
			j++;
		if (j > max)
			max = j;
		j = 0;
		i++;
	}
	return (max);
}

static int	get_height(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

static void	fill_str(t_map *map, char **arr, int i)
{
	int	j;

	j = 0;
	while (arr[i][j] && arr[i][j] != '\n')
	{
		map->map_tab[i][j] = arr[i][j];
		j++;
	}
	while (j < map->width)
	{
		map->map_tab[i][j] = ' ';
		j++;
	}
	map->map_tab[i][map->width] = '\0';
}

static int	fill_map(t_map *map, char **scene)
{
	int	i;

	i = 0;
	while (scene[i])
	{
		map->map_tab[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->map_tab[i])
			return (print_error(NULL, strerror(errno), errno));
		fill_str(map, scene, i);
		i++;
	}
	map->map_tab[i] = NULL;
	return (0);
}

int	get_map(t_data *data)
{
	int	i;

	i = find_mapstart(data->scenery.scene);
	if (i == -1)
		return (print_error(NULL, ERR_MAP, 1));
	data->map.height = get_height(&data->scenery.scene[i]);
	data->map.width = get_width(&data->scenery.scene[i]);
	data->map.map_tab = malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.map_tab)
		return (print_error(NULL, strerror(errno), errno));
	if (fill_map(&data->map, &data->scenery.scene[i]))
	{
		free(data->map.map_tab);
		return (1);
	}
	return (0);
}
