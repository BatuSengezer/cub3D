/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:27:27 by joschka           #+#    #+#             */
/*   Updated: 2024/11/21 10:00:34 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	emptystr(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] && flag == 1)
	{
		if (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			i++;
		else
			flag = 0;
	}
	return (flag);
}

static int	get_linenumber(char *path)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno), errno));
	else
	{
		line = get_next_line(fd);
		while (line)
		{
			if (!emptystr(line))
				count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (count);
}

static void	ft_simpstrcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return ;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	fill_scene(t_scenery *scenery)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(scenery->fd);
	while (line)
	{
		if (!emptystr(line))
		{
			scenery->scene[i] = malloc(ft_strlen(line) + 1 * sizeof(char));
			if (!scenery->scene[i])
			{
				free_array(scenery->scene);
				return (print_error(NULL, strerror(errno), errno));
			}
			ft_simpstrcpy(scenery->scene[i], line);
			i++;
		}
		free(line);
		line = get_next_line(scenery->fd);
	}
	scenery->scene[i] = NULL;
	close(scenery->fd);
	return (0);
}

int	get_scene(t_scenery *scenery)
{
	scenery->lcount = get_linenumber(scenery->s_path);
	scenery->scene = malloc((scenery->lcount + 1) * sizeof(char *));
	if (!scenery->scene)
		return (print_error(NULL, strerror(errno), errno));
	scenery->fd = open(scenery->s_path, O_RDONLY);
	if (scenery->fd == -1)
		return (print_error(scenery->s_path, strerror(errno), errno));
	if (fill_scene(scenery))
		return (1);
	return (0);
}
