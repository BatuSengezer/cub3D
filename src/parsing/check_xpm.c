/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:46:10 by bsengeze          #+#    #+#             */
/*   Updated: 2024/12/13 06:48:20 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'm' || path[len - 2] != 'p' || path[len - 3] != 'x'
		|| path[len - 4] != '.')
		return (1);
	return (0);
}

int	check_xpm_file(char *path)
{
	int	fd;

	// fd = open(path, __O_DIRECTORY);
	fd = open(path, O_DIRECTORY); // macos
	if (fd > 0)
	{
		close(fd);
		return (print_error(path, ERR_DIR, 1));
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno), errno));
	close(fd);
	if (check_xpm_extension(path))
		return (print_error(path, ERR_XPM, 1));
	return (0);
}

int	check_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (i == 1)
			cut_newline(arr);
		if (i == 1 && check_xpm_file(arr[i]))
			return (1);
		i++;
	}
	if (i == 1)
		return (print_error(arr[0], ERR_TEX, 1));
	if (i > 2)
		return (print_error(arr[0], ERR_TEXT, 1));
	return (0);
}
