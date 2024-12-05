/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:53:31 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/05 13:55:21 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void	draw_vertical_line(t_data *data, int x, int wall_height)
{
	int	draw_start;
	int	draw_end;
	int	y;
	int	c_color;
	int	f_color;

	c_color = get_rgb(data->textures.ceiling);
	f_color = get_rgb(data->textures.floor);
	draw_start = (HEIGHT - wall_height) / 2;
	draw_end = draw_start + wall_height;
	y = 0;
	// Draw ceiling
	while (y < draw_start)
		my_pixel_put(&data->game.img, x, y++, c_color);
	// Draw wall
	while (y < draw_end)
		my_pixel_put(&data->game.img, x, y++, 0xFFFFFF);
	// Draw floor
	while (y < HEIGHT)
		my_pixel_put(&data->game.img, x, y++, f_color);
}

static float	get_wall_distance(t_data *data, float start_x, float x, float y)
{
	float	distance;
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;

	distance = 0;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = x;
	ray_y = y;
	while (distance < (WIDTH + HEIGHT))
	{
		if (collision(data, ray_x, ray_y))
			break ;
		ray_x += cos_angle * 0.5;
		ray_y += sin_angle * 0.5;
		distance += 0.5;
	}
	return (distance * cos(start_x - data->game.player.angle));
}

void	raycasting(int x, int y, t_data *data)
{
	float	start_x;
	float	fraction;
	float	distance;
	int		wall_height;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = data->game.player.angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		distance = get_wall_distance(data, start_x, x, y);
		wall_height = (BLOCK * HEIGHT) / distance;
		// Prevent overflow for close walls
		if (wall_height > HEIGHT)
			wall_height = HEIGHT;
		draw_vertical_line(data, i, wall_height);
		start_x += fraction;
		i++;
	}
}