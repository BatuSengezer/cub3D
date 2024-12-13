/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:53:31 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/13 17:20:25 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_ray	calculate_ray(t_data *data, float angle, float x, float y)
{
	t_ray	ray;

	ray.step_x = cos(angle);
	ray.step_y = sin(angle);
	prepare_dda(&ray, x, y);
	perform_dda(data, &ray, x, y);
	x = ray.hit_x;
	y = ray.hit_y;
	if (ray.side == 0)
	{
		ray.direction = get_direction(ray.step_x, ray.side);
		ray.wall_x = (y / BLOCK) - floor(y / BLOCK);
	}
	else
	{
		ray.direction = get_direction(ray.step_y, ray.side);
		ray.wall_x = (x / BLOCK) - floor(x / BLOCK);
	}
	ray.distance = sqrt(pow(x - data->game.player.x, 2) + pow(y
				- data->game.player.y, 2));
	ray.distance *= cos(angle - data->game.player.angle);
	return (ray);
}

static void	get_line_vars(t_line *l, t_data *data, int wall_height, t_ray *ray)
{
	l->draw_start = (HEIGHT - wall_height) / 2;
	l->draw_end = l->draw_start + wall_height;
	if (l->draw_start < 0)
		l->y_start = 0;
	else
		l->y_start = l->draw_start;
	if (l->draw_end >= HEIGHT)
		l->y_end = HEIGHT - 1;
	else
		l->y_end = l->draw_end;
	l->tex = data->textures.tex[ray->direction];
	l->tex_x = (int)(ray->wall_x * l->tex->width);
	if (l->tex_x >= l->tex->width)
		l->tex_x = l->tex->width - 1;
}

static void	draw_wall(t_data *data, t_line *l, int x, int wall_height)
{
	int			y;
	float		tex_pos;
	int			tex_y;
	char		*pixel;
	int			color;

	y = l->y_start;
	while (y < l->y_end)
	{
		tex_pos = (float)(y - l->draw_start) / wall_height;
		tex_y = (int)(tex_pos * l->tex->height);
		if (tex_y >= l->tex->height)
			tex_y = l->tex->height - 1;
		if (tex_y < 0)
			tex_y = 0;
		pixel = l->tex->addr + (tex_y * l->tex->line_length + l->tex_x
				* (l->tex->bits_per_pixel / 8));
		color = *(unsigned int *)pixel;
		my_pixel_put(&data->game.img, x, y, color);
		y++;
	}
}

static void	draw_textured_line(t_data *data, int x, int wall_height, t_ray ray)
{
	t_line	line;
	int		y;

	y = 0;
	get_line_vars(&line, data, wall_height, &ray);
	while (y < line.y_start)
	{
		my_pixel_put(&data->game.img, x, y, get_rgb(data->textures.ceiling));
		y++;
	}
	draw_wall(data, &line, x, wall_height);
	y = line.y_end;
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

	fraction = PI / 3 / WIDTH;
	start_x = data->game.player.angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		ray = calculate_ray(data, start_x, x, y);
		wall_height = (BLOCK * HEIGHT) / ray.distance;
		draw_textured_line(data, i, wall_height, ray);
		start_x += fraction;
		i++;
	}
	draw_minimap(data);
}
