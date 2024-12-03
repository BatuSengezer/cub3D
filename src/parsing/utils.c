/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:17:09 by joschka           #+#    #+#             */
/*   Updated: 2024/11/22 11:36:25 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cut_newline(char **arr)
{
	int		len;
	char	*tmp;

	len = ft_strlen(arr[1]);
	if (arr[1][len - 1] == '\n')
	{
		tmp = malloc((len) * sizeof(char));
		ft_strlcpy(tmp, arr[1], len);
		free(arr[1]);
		arr[1] = tmp;
	}
}

int	find_mapstart(char **arr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (arr[i])
	{
		j = skip_space(arr[i]);
		if (arr[i][j] == '1')
			return (i);
		j = 0;
		i++;
	}
	return (-1);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
