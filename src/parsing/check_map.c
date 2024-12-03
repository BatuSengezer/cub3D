/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:27:43 by joschka           #+#    #+#             */
/*   Updated: 2024/11/22 11:39:02 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_wall(t_map *map, int row, int col)
{
	char	c;

	if (row < 0 || row >= map->height || col < 0 || col >= map->width)
		return ;
	c = map->map_tab[row][col];
	if (c == '1')
		return ;
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		map->not_surrounded++;
	if (c == ' ')
	{
		map->map_tab[row][col] = 'X';
		check_wall(map, row - 1, col);
		check_wall(map, row + 1, col);
		check_wall(map, row, col - 1);
		check_wall(map, row, col + 1);
	}
	return ;
}

static int	check_border(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != 'X')
			ret++;
		i++;
	}
	return (ret);
}

static int	check_edge(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] != '1' && str[i] != ' ' && str[i] != 'X')
		ret++;
	while (str[i])
		i++;
	if (str[i - 1] != '1' && str[i - 1] != ' ' && str[i - 1] != 'X')
		ret++;
	return (ret);
}

static void	run_checks(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->not_surrounded += check_border(map->map_tab[i]);
	while (map->map_tab[i])
	{
		j = 0;
		map->not_surrounded += check_edge(map->map_tab[i]);
		while (map->map_tab[i][j])
		{
			if (map->map_tab[i][j] == ' ')
				check_wall(map, i, j);
			map->player_count += is_player(map->map_tab[i][j]);
			j++;
		}
		i++;
	}
	map->not_surrounded += check_border(map->map_tab[i - 1]);
}

int	check_map(t_map *map)
{
	run_checks(map);
	print_array(map->map_tab);
	if (map->not_surrounded)
	{
		print_error(NULL, ERR_WALL, 1);
		ft_printf("Problems: %d\n", map->not_surrounded);
		return (1);
	}
	if (map->player_count != 1)
		return (print_error(NULL, ERR_PLAYCOUNT, 1));
	return (0);
}
