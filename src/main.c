/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:26 by joschka           #+#    #+#             */
/*   Updated: 2024/11/22 16:17:29 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}

void	print_colorcode(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_printf("%d, ", color[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error(NULL, ERR_USAGE, 1));
	init(&data);
	if (parsing(argv[1], &data))
		return (1);
	game(&data);
	squeaky_clean(&data);
	return (0);
}
