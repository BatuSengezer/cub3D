/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:34:44 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/04 13:36:47 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image(t_img *img)
{
	int	i;
	int	k;
	
	i = 0;
	while (i < HEIGHT)
	{
		k = 0;
		while (k < WIDTH)
		{
			my_pixel_put(img, k, i, 0);
			k++;
		}
		i++;
	}
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	dst = img->img_pixels_ptr + offset;
	*(unsigned int *)dst = color;
}
