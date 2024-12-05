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
static t_ray get_wall_hit(t_data *data, float angle, float x, float y)
{
    t_ray ray;
    float step_x = cos(angle) * 0.1;
    float step_y = sin(angle) * 0.1;
    
    ray.distance = 0;
    while (!collision(data, x, y))
    {
        x += step_x;
        y += step_y;
        ray.distance += 0.1;
    }
    
    // Determine wall direction based on hit position
    if (step_x > 0 && collision(data, x - 0.1, y))
        ray.direction = 3;  // WE wall
    else if (step_x < 0 && collision(data, x + 0.1, y))
        ray.direction = 2;  // EA wall
    else if (step_y > 0 && collision(data, x, y - 0.1))
        ray.direction = 1;  // SO wall
    else
        ray.direction = 0;  // NO wall
        
    // Calculate wall_x (0-1 position on wall)
    if (ray.direction < 2)  // NO or SO
        ray.wall_x = x - floor(x);
    else
        ray.wall_x = y - floor(y);
        
    return ray;
}

static void draw_textured_line(t_data *data, int x, int wall_height, t_ray ray)
{
    int draw_start = (HEIGHT - wall_height) / 2;
    int draw_end = draw_start + wall_height;
    t_tex_img *tex = data->textures.tex[ray.direction];
    int tex_x = ray.wall_x * tex->width;
    
    for (int y = draw_start; y < draw_end; y++)
    {
        float tex_pos = (y - draw_start) / (float)wall_height;
        int tex_y = tex_pos * tex->height;
        char *pixel = tex->addr + (tex_y * tex->line_length + 
                                 tex_x * (tex->bits_per_pixel / 8));
        int color = *(unsigned int*)pixel;
        my_pixel_put(&data->game.img, x, y, color);
    }
}

void	raycasting(int x, int y, t_data *data)
{
	(void)x;  // Suppress unused parameter warning
	(void)y;  // Suppress unused parameter warning

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
		ray = get_wall_hit(data, start_x, data->game.player.x, data->game.player.y);
		wall_height = (BLOCK * HEIGHT) / ray.distance;
		if (wall_height > HEIGHT)
			wall_height = HEIGHT;
		draw_textured_line(data, i, wall_height, ray);
		start_x += fraction;
		i++;
	}
}