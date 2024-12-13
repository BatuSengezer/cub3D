/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:26 by joschka           #+#    #+#             */
/*   Updated: 2024/12/13 18:01:34 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error(NULL, ERR_USAGE, 1));
	init(&data);
	if (parsing(argv[1], &data))
	{
		free(data.textures.tex);
		return (1);
	}
	game(&data);
	squeaky_clean(&data);
	return (0);
}
