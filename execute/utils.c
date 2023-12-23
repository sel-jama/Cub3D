/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:42:14 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/23 06:45:32 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_ditected(const char *error)
{
	ft_putstr_fd("Error\n", 2);
	write(2, error, ft_strlen(error));
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	init_ray_h(t_ray *ray, double ray_angle)
{
	ray->angle = normalize_angle(ray_angle);
	ray->hit_hx = 0;
	ray->hit_hy = 0;
	ray->facing_down = 0;
	ray->facing_left = 0;
	ray->facing_up = 0;
	ray->facing_right = 0;
	ray->found_h_hit = 0;
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->facing_down = 1;
	if (!ray->facing_down)
		ray->facing_up = 1;
	if (ray->angle < 0.5 * M_PI || ray->angle > 1.5 * M_PI)
		ray->facing_right = 1;
	if (!ray->facing_right)
		ray->facing_left = 1;
}

void	init_ray_v(t_ray *ray)
{
	ray->found_v_hit = 0;
	ray->hit_vx = 0;
	ray->hit_vy = 0;
}

double	get_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
