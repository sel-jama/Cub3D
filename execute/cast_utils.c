/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 07:02:32 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/23 09:24:34 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	closest_distance(t_game **cast, t_ray *ray)
{
	double	h_dis;
	double	v_dis;
	t_game	*p;

	h_dis = INT_MAX;
	v_dis = INT_MAX;
	p = *cast;
	if (ray->found_v_hit != -1 && ray->found_v_hit == 1)
		v_dis = get_distance(p->pos_x, p->pos_y, ray->hit_vx, ray->hit_vy);
	if (ray->found_h_hit != -1 && ray->found_h_hit == 1)
		h_dis = get_distance(p->pos_x, p->pos_y, ray->hit_hx, ray->hit_hy);
	if (h_dis < v_dis)
	{
		ray->hit_x = ray->hit_hx;
		ray->hit_y = ray->hit_hy;
		ray->dis = h_dis;
		ray->hit_is_v = 0;
	}
	else
	{
		ray->hit_x = ray->hit_vx;
		ray->hit_y = ray->hit_vy;
		ray->dis = v_dis;
		ray->hit_is_v = 1;
	}
}

int	first_horz_inter(t_game **cub, t_ray *ray, double *dx, double *dy)
{
    double  epsilon;

    epsilon = 1e-3;
	if (fabs(ray->angle - 2 * M_PI) < epsilon || fabs(ray->angle - M_PI) < epsilon)
	{
		ray->found_h_hit = -1;
		return (0);
	}
	*dy = floor((*cub)->pos_y / 32) * 32;
	if (ray->facing_down)
		*dy += 32;
	*dx = (*cub)->pos_x + (*dy - (*cub)->pos_y) / tan(ray->angle);
	return (1);
}

int	first_vert_inter(t_game **cub, t_ray *ray, double *dx, double *dy)
{
    double  epsilon;

    epsilon = 1e-3;
	if (fabs(ray->angle - (1.5 * M_PI)) < epsilon || fabs(ray->angle - 0.5 * M_PI) < epsilon)
	{
		ray->found_v_hit = -1;
		return (0);
	}
	*dx = floor((*cub)->pos_x / 32) * 32;
	if (ray->facing_right)
		*dx += 32;
	*dy = (*cub)->pos_y + (*dx - (*cub)->pos_x) * tan(ray->angle);
	return (1);
}

void	calculate_horz_step(int size, t_ray *ray, double *x, double *y)
{
	double	xstep;
	double	ystep;

	ystep = size;
	if (ray->facing_up)
		ystep *= -1;
	xstep = size / tan(ray->angle);
	if (ray->facing_left && xstep > 0)
		xstep *= -1;
	if (ray->facing_right && xstep < 0)
		xstep *= -1;
	*x = xstep;
	*y = ystep;
}

void	calculate_vert_step(int size, t_ray *ray, double *x, double *y)
{
	double	xstep;
	double	ystep;

	xstep = size;
	if (ray->facing_left)
		xstep *= -1;
	ystep = size * tan(ray->angle);
	if ((ray->facing_up && ystep > 0) || (ray->facing_down && ystep < 0))
		ystep *= -1;
	*x = xstep;
	*y = ystep;
}
