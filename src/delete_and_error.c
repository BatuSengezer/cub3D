/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_and_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:32 by joschka           #+#    #+#             */
/*   Updated: 2024/11/28 17:51:30 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	clean_exit(t_data *data, int code)
{
	squeaky_clean(data);
	exit(code);
}

void	squeaky_clean(t_data *data)
{
	if (data->scenery.scene)
		free_array(data->scenery.scene);
	if (data->textures.north)
		free_array(data->textures.north);
	if (data->textures.south)
		free_array(data->textures.south);
	if (data->textures.west)
		free_array(data->textures.west);
	if (data->textures.east)
		free_array(data->textures.east);
	if (data->textures.floor)
		free(data->textures.floor);
	if (data->textures.ceiling)
		free(data->textures.ceiling);
	if (data->map.map_tab)
		free_array(data->map.map_tab);
	if (data->game.mlx)
		free(data->game.mlx);
}

int	print_error(char *src, char *str, int errcode)
{
	ft_putstr_fd("Error\n", 2);
	if (src)
	{
		ft_putstr_fd(src, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (errcode);
}
