/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 07:02:32 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/22 07:11:00 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void closest_distance(t_game **cast, t_ray *ray)
{
    double h_dis = INT_MAX;
    double v_dis = INT_MAX;

    if (ray->found_v_hit != -1 && ray->found_v_hit == 1)
        v_dis = get_distance((*cast)->pos_x, (*cast)->pos_y, ray->hit_vx, ray->hit_vy);
    if (ray->found_h_hit != -1 && ray->found_h_hit == 1)
        h_dis = get_distance((*cast)->pos_x, (*cast)->pos_y, ray->hit_hx, ray->hit_hy);

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

int first_horz_inter(t_game **cub, t_ray *ray, double *dx, double *dy)
{
    *dy = floor((*cub)->pos_y / (*cub)->size) * (*cub)->size;
    if (ray->facing_down)
        *dy += (*cub)->size;
    if (ray->angle == 2 * M_PI || ray->angle == M_PI)
    {
        ray->found_h_hit = -1;
        return (0);
    }
    *dx = (*cub)->pos_x + (*dy - (*cub)->pos_y) / tan(ray->angle);
    return (1);
}

int first_vert_inter(t_game **cub, t_ray *ray, double *dx, double *dy)
{
    *dx = floor((*cub)->pos_x / (*cub)->size) * (*cub)->size;
    if (ray->facing_right)
        *dx += (*cub)->size;
    if (ray->angle == (1.5 * M_PI) || ray->angle == 0.5 * M_PI)
    {
        ray->found_v_hit = -1;
        return (0);
    }
    *dy = (*cub)->pos_y + (*dx - (*cub)->pos_x) * tan(ray->angle);
    return (1);
}

void calculate_horz_step(int size, t_ray *ray, double *x, double *y)
{
    double xstep;
    double ystep;

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


void calculate_vert_step(int size, t_ray *ray, double *x, double *y)
{
    double xstep;
    double ystep;
        
    xstep = size;
    if (ray->facing_left)
        xstep *= -1;
    // else
    //     xstep += 0.0001;
    ystep = size * tan(ray->angle);
    if ((ray->facing_up && ystep > 0) || (ray->facing_down && ystep < 0))
        ystep *= -1;
    *x = xstep;
    *y = ystep;
}