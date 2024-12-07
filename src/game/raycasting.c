/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:53:31 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/07 22:28:38 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
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
 */
static t_ray	get_wall_hit(t_data *data, float angle, float x, float y)
{
	t_ray	ray;
	float	step_x;
	float	step_y;
	float	delta_x;
	float	delta_y;
	float	side_dist_x;
	float	side_dist_y;
	int		map_x;
	int		map_y;

	step_x = cos(angle);
	step_y = sin(angle);
	delta_x = (step_x == 0) ? 1e30 : fabs(1.0 / step_x);
	delta_y = (step_y == 0) ? 1e30 : fabs(1.0 / step_y);
	// Calculate initial side distances
	side_dist_x = (step_x < 0) ? (x - floor(x)) * delta_x : (ceil(x) - x)
		* delta_x;
	side_dist_y = (step_y < 0) ? (y - floor(y)) * delta_y : (ceil(y) - y)
		* delta_y;
	map_x = (int)x;
	map_y = (int)y;
	int side; // 0 for x-side, 1 for y-side
	// Perform DDA
	while (!collision(data, x, y))
	{
		// Jump to next square
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_x;
			map_x += (step_x > 0) ? 1 : -1;
			side = 0;
		}
		else
		{
			side_dist_y += delta_y;
			map_y += (step_y > 0) ? 1 : -1;
			side = 1;
		}
		x = map_x;
		y = map_y;
	}
	// Calculate exact hit position and direction
	if (side == 0)
	{                                         // Vertical wall (East/West)
		ray.direction = (step_x > 0) ? 3 : 2; // 3=West, 2=East
		ray.wall_x = y - floor(y);
	}
	else
	{                                         // Horizontal wall (North/South)
		ray.direction = (step_y > 0) ? 1 : 0; // 1=South, 0=North
		ray.wall_x = x - floor(x);
	}
	ray.distance = sqrt(pow(x - data->game.player.x, 2) + pow(y
				- data->game.player.y, 2));
	ray.distance *= cos(angle - data->game.player.angle); // Fix fisheye
	return (ray);
}

static void	draw_textured_line(t_data *data, int x, int wall_height, t_ray ray)
{
	int			draw_start;
	int			draw_end;
	t_tex_img	*tex;
	int			tex_x;
	float		tex_pos;
	int			tex_y;
	char		*pixel;
	int			color;
	int			y;

	draw_start = (HEIGHT - wall_height) / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = draw_start + wall_height;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	tex = data->textures.tex[ray.direction];
	tex_x = (int)(ray.wall_x * tex->width);
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	// Draw ceiling
	y = 0;
	while (y < draw_start)
	{
		my_pixel_put(&data->game.img, x, y, get_rgb(data->textures.ceiling));
		y++;
	}
	// Draw wall
	y = draw_start;
	while (y < draw_end)
	{
		tex_pos = (float)(y - draw_start) / wall_height;
		tex_y = (int)(tex_pos * tex->height);
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		pixel = tex->addr + (tex_y * tex->line_length + tex_x
				* (tex->bits_per_pixel / 8));
		color = *(unsigned int *)pixel;
		my_pixel_put(&data->game.img, x, y, color);
		y++;
	}
	// Draw floor
	y = draw_end;
	while (y < HEIGHT)
	{
		my_pixel_put(&data->game.img, x, y, get_rgb(data->textures.floor));
		y++;
	}
}

void	raycasting(int x, int y, t_data *data)
{
	float	start_x;
	float	fraction;
	t_ray	ray;
	int		wall_height;
	int		i;

	(void)x; // Suppress unused parameter warning
	(void)y; // Suppress unused parameter warning
	fraction = PI / 3 / WIDTH;
	start_x = data->game.player.angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		ray = get_wall_hit(data, start_x, data->game.player.x,
				data->game.player.y);
		wall_height = (BLOCK * HEIGHT) / ray.distance;
		if (wall_height > HEIGHT)
			wall_height = HEIGHT;
		draw_textured_line(data, i, wall_height, ray);
		start_x += fraction;
		i++;
	}
	draw_minimap(data);
}
