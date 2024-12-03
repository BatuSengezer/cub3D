/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:21:17 by joschka           #+#    #+#             */
/*   Updated: 2024/11/22 11:38:59 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_number(int number, char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	if (number < 0 || number > 255)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			flag = 0;
		i++;
	}
	return (flag);
}

static int	*convert_color(char **arr, int *color)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		color[i] = ft_atoi(arr[i]);
		if (check_number(color[i], arr[i]))
		{
			free_array(arr);
			free(color);
			print_error(NULL, ERR_COLOR, 0);
			return (NULL);
		}
		i++;
	}
	free_array(arr);
	return (color);
}

static int	*check_colors(char *str)
{
	char	**tmp;
	int		i;
	int		*colors;

	i = 0;
	tmp = ft_split(str, ',');
	if (!tmp)
		return (NULL);
	while (tmp[i])
		i++;
	if (i != 3)
	{
		print_error(NULL, ERR_COLOR, 0);
		free_array(tmp);
		return (NULL);
	}
	colors = malloc(sizeof(int) * 3);
	if (!colors)
	{
		print_error(NULL, strerror(errno), errno);
		free_array(tmp);
		return (NULL);
	}
	return (convert_color(tmp, colors));
}

static int	set_colors(char *str, int **ptr)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(str, ' ');
	if (!arr)
		return (1);
	while (arr[i])
	{
		if (i == 1)
			*ptr = check_colors(arr[i]);
		i++;
	}
	free_array(arr);
	if (!*ptr)
		return (1);
	if (i == 1)
		return (print_error(arr[0], ERR_TE, 1));
	if (i > 2)
		return (print_error(arr[0], ERR_TEXT, 1));
	return (0);
}

int	get_colors(t_data *data)
{
	char	**arr;
	int		i;
	int		ret;
	int		j;

	i = 0;
	ret = 0;
	j = 0;
	arr = data->scenery.scene;
	while (arr[i])
	{
		if (ret)
			break ;
		j = skip_space(arr[i]);
		if (!ft_strncmp(&arr[i][j], "F", 1) && !ret)
			ret = set_colors(&arr[i][j], &data->textures.floor);
		if (!ft_strncmp(&arr[i][j], "C", 1) && !ret)
			ret = set_colors(&arr[i][j], &data->textures.ceiling);
		i++;
	}
	return (ret);
}
