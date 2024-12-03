/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:32:19 by joschka           #+#    #+#             */
/*   Updated: 2024/11/21 14:44:04 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	check_elements(char **scene)
{
	int	i;
	int	j;

	i = 0;
	while (scene[i])
	{
		j = skip_space(scene[i]);
		if (!ft_strncmp(&scene[i][j], "NO ", 3)
			|| !ft_strncmp(&scene[i][j], "SO ", 3)
			|| !ft_strncmp(&scene[i][j], "WE ", 3)
			|| !ft_strncmp(&scene[i][j], "EA ", 3)
			|| !ft_strncmp(&scene[i][j], "F ", 2)
			|| !ft_strncmp(&scene[i][j], "C ", 2)
			|| !ft_strncmp(&scene[i][j], "1", 1))
			i++;
		else
			return (print_error(ERR_ELEMENT, ERR_LABORD, 1));
	}
	return (0);
}

static int	check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1'
			&& str[i] != '0' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	map_last(char **scene)
{
	int	i;
	int	mapflag;
	int	j;

	i = 0;
	mapflag = 0;
	while (scene[i])
	{
		j = skip_space(scene[i]);
		if (!strncmp(&scene[i][j], "1", 1))
			mapflag = 1;
		if (mapflag && strncmp(&scene[i][j], "1", 1))
			return (print_error(ERR_LAST, ERR_LABORD, 1));
		if (mapflag && check_chars(&scene[i][j]))
			return (print_error(NULL, ERR_CHAR, 1));
		i++;
	}
	return (0);
}
