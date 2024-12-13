/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:14:51 by jbeck             #+#    #+#             */
/*   Updated: 2024/12/13 17:52:27 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	get_delta(float step)
{
	float	delta;

	if (step == 0)
		delta = 1e30;
	else
		delta = fabs(1.0 / step);
	return (delta);
}

static float	get_side_distance(t_ray *ray, float x, float y, int axis)
{
	float	distance;

	if (axis == 0)
	{
		if (ray->step_x < 0)
			distance = (x - floor(x)) * ray->delta_x;
		else
			distance = (ceil(x) - x) * ray->delta_x;
	}
	else
	{
		if (ray->step_y < 0)
			distance = (y - floor(y)) * ray->delta_y;
		else
			distance = (ceil(y) - y) * ray->delta_y;
	}
	return (distance);
}

static int	get_step(float step)
{
	int	direction;

	if (step > 0)
		direction = 1;
	else
		direction = -1;
	return (direction);
}

void	prepare_dda(t_ray *ray, float x, float y)
{
	ray->delta_x = get_delta(ray->step_x);
	ray->delta_y = get_delta(ray->step_y);
	ray->side_dist_x = get_side_distance(ray, x, y, 0);
	ray->side_dist_y = get_side_distance(ray, x, y, 1);
}

void	perform_dda(t_data *data, t_ray *ray, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	while (!collision(data, x, y))
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			map_x += get_step(ray->step_x);
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			map_y += get_step(ray->step_y);
			ray->side = 1;
		}
		x = map_x;
		y = map_y;
	}
	ray->hit_x = x;
	ray->hit_y = y;
}
